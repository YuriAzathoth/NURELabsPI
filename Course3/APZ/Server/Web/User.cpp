#include "PCH.h"
#include "Shared/ServerContext.h"
#include "Web/CookiesManager.h"
#include "Web/Localization.h"
#include "Web/PageManager.h"
#include "User.h"
#include "Utility.h"

using namespace Poco::Data::Keywords;

User::User(ServerContext* global_context, CookiesManager &cookies, PageManager &pagemgr) :
	IObject(global_context),
	ICookieDependentObject(cookies),
	IPageControllerObject(pagemgr),
	m_logged(false)
{
	m_token = GetCookies().GetToken();
	if (m_token.empty())
		return;
	GetContext()->GetDb().NewSession() << R"(SELECT "VALIDATE_USER_TOKEN"(?))", use(m_token), into(m_logged), now;
	if (m_logged)
		UpdateData();
	else
		LogOut();
}

void User::LogIn(const std::string &login, std::string pass)
{
	HashPassword(pass);
	TryLogIn(login, pass);
	UpdateData();
	if (!m_token.empty())
		SetPage(PageManager::GetHome(true, static_cast<int>(m_role)));
	else
		GetCookies().SetError("error.login");
}

void User::LogOut()
{
	m_token.clear();
	m_logged = false;
	GetCookies().ResetToken();
	SetPage(PageManager::EPage::USER_LOGIN);
}

void User::Register(std::string login, std::string pass1, std::string pass2, std::string email, std::string name)
{
	FromUtf8(name);
	HashPassword(pass1);
	HashPassword(pass2);

	ERegResult result;
	GetContext()->GetDb().NewSession() << R"(SELECT "REGISTER_USER"(?, ?, ?, ?, ?))",
		use(login), use(pass1), use(pass2), use(email), use(name), into(reinterpret_cast<int&>(result)), now;
	if (result == ERegResult::OK)
		GetContext()->GetEmail().SendVerification(email, name, GenConfirmToken(login, pass1), Localization(GetContext(), GetCookies()));

	switch (result)
	{
	case User::ERegResult::OK:
		SetPage(PageManager::EPage::HOME_CLIENT);
		return;
	case User::ERegResult::INVALID_LOGIN:
		GetCookies().SetError("error.invlogin");
		break;
	case User::ERegResult::INVALID_EMAIL:
		GetCookies().SetError("error.invemail");
		break;
	case User::ERegResult::INVALID_NAME:
		GetCookies().SetError("error.invname");
		break;
	case User::ERegResult::DIFFERENT_PASS:
		GetCookies().SetError("error.invpass");
		break;
	case User::ERegResult::BUSY_LOGIN:
		GetCookies().SetError("error.busylogin");
		break;
	case User::ERegResult::BUSY_EMAIL:
		GetCookies().SetError("error.busyemail");
		break;
	}
}

void User::EditLogin(const std::string &login)
{
	bool result;
	GetContext()->GetDb().NewSession() << R"(SELECT "CHANGE_USER_LOGIN"(?, ?))", use(m_token), bind(login), into(result), now;
	if (result)
		LogOut();
	else
        GetCookies().SetError("error.invlogin");
}

void User::EditPass(std::string pass1, std::string pass2)
{
	HashPassword(pass1);
	HashPassword(pass2);
	bool result;
	GetContext()->GetDb().NewSession() << R"(SELECT "CHANGE_USER_PASS"(?, ?, ?))", use(m_token), bind(pass1), bind(pass2), into(result), now;
	if (result)
		TryLogIn(m_login, pass1);
	else
        GetCookies().SetError("error.invpass");
}

void User::EditEmail(const std::string &email)
{
	bool result;
	GetContext()->GetDb().NewSession() << R"(SELECT "CHANGE_USER_EMAIL"(?, ?))", use(m_token), bind(email), into(result), now;
	if (!result)
        GetCookies().SetError("error.invemail");
}

void User::EditName(std::string name)
{
	bool result;
	FromUtf8(name);
	GetContext()->GetDb().NewSession() << R"(SELECT "CHANGE_USER_NAME"(?, ?))", use(m_token), bind(name), into(result), now;
	if (!result)
        GetCookies().SetError("error.invname");
}

void User::Confirm(const std::string &token)
{
	GetContext()->GetDb().NewSession() << R"(CALL "CONFIRM_EMAIL"(?))", bind(token), now;
}

void User::UpdateData()
{
	GetContext()->GetDb().NewSession() << R"(SELECT * FROM "GET_USER_DATA"(?))", use(m_token), into(m_id), into(m_login), into(m_email), into(m_name), into(reinterpret_cast<int&>(m_role)), now;
	ToUtf8(m_name);
}

void User::HashPassword(std::string &pass)
{
	Poco::MD5Engine md5engine;
	md5engine.update(pass);
	pass = Poco::DigestEngine::digestToHex(md5engine.digest());
}

void User::TryLogIn(const std::string &login, const std::string &pass)
{
	m_token.clear();
	GetContext()->GetDb().NewSession() << R"(SELECT "AUTHORIZE_USER"(?, ?))", bind(login), bind(pass), into(m_token), now;
	if (!m_token.empty())
	{
		GetCookies().SetToken(m_token);
		UpdateData();
	}
}

std::string User::GenConfirmToken(const std::string &login, std::string pass)
{
	HashPassword(pass);
	std::string token = login + ">" + pass;
	HashPassword(token);
	return token;
}
