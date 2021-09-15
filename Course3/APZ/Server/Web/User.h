#ifndef USERSSYSTEM_H
#define USERSSYSTEM_H

#include "Shared/IObject.h"
#include "Web/ICookieDependentObject.h"
#include "Web/IPageControllerObject.h"

class CookiesManager;

class User : public IObject, public ICookieDependentObject, public IPageControllerObject
{
public:
	User(ServerContext* global_context, CookiesManager &cookies, PageManager &pagemgr);

	enum class ERegResult
	{
		OK,
		DIFFERENT_PASS,
		INVALID_LOGIN,
		INVALID_EMAIL,
		INVALID_NAME,
		BUSY_LOGIN,
		BUSY_EMAIL
	};
	enum class ERole
	{
		CLIENT,
		ADMINISTRATOR
	};

    void LogIn	(const std::string &login, std::string pass);
	void LogOut	();
	void Confirm(const std::string &token);

	const std::string &GetLogin	() const noexcept { return m_login; }
	const std::string &GetEmail	() const noexcept { return m_email; }
	const std::string &GetName	() const noexcept { return m_name; }
	const std::string &GetToken	() const noexcept { return m_token; }

	bool		IsLoggedIn	() const noexcept { return m_logged; }
    ERole		GetRole		() const noexcept { return m_role; }
	uint32_t	GetId		() const noexcept { return m_id; }

	void Register(std::string login, std::string pass1, std::string pass2, std::string email, std::string name);

	void EditLogin	(const std::string &login);
	void EditPass	(std::string pass1, std::string pass2);
	void EditEmail	(const std::string &email);
	void EditName	(std::string name);

private:
	void UpdateData	();
	void TryLogIn	(const std::string &login, const std::string &pass);

	std::string	m_token;
	std::string	m_login;
	std::string	m_email;
	std::string	m_name;
	uint32_t	m_id;
	ERole		m_role;
	bool		m_logged;

	static void			HashPassword	(std::string &pass);
	static std::string	GenConfirmToken	(const std::string &login, std::string pass);
};

#endif // USERSSYSTEM_H
