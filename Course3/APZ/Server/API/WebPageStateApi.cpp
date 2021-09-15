#include "PCH.h"
#include "Web/WebContext.h"
#include "WebPageStateApi.h"

void WebPageStateApi::HandleControl()
{
	GenerateGranted();
	SetPage();
}
void WebPageStateApi::GenerateGranted()
{
	User &user = m_context->GetUser();
	m_pages.emplace("home", m_context->GetHomePage());
	if (user.IsLoggedIn())
	{
		m_pages.emplace("useredit",	PageManager::EPage::USER_EDIT);
		m_pages.emplace("addprod",	PageManager::EPage::PRODUCT_ADD);
		if (user.GetRole() == User::ERole::ADMINISTRATOR)
		{
			m_pages.emplace("admin-warehouses",	PageManager::EPage::HOME_ADMIN_WAREHOUSES);
			m_pages.emplace("admin-categories",	PageManager::EPage::HOME_ADMIN_CATEGORIES);
			m_pages.emplace("admin-products",	PageManager::EPage::HOME_ADMIN_PRODUCTS);
			m_pages.emplace("admin-regware",	PageManager::EPage::HOME_ADMIN_REG_WARE);
			m_pages.emplace("admin-regcat",		PageManager::EPage::HOME_ADMIN_REG_CAT);
			m_pages.emplace("admin-addprod",	PageManager::EPage::HOME_ADMIN_ADD_PROD);
			m_pages.emplace("admin-ware-store",	PageManager::EPage::HOME_ADMIN_WARE_STORE);
			m_pages.emplace("admin-ware-view",	PageManager::EPage::HOME_ADMIN_WARE_VIEW);
		}
	}
	else
	{
		m_pages.emplace("login",	PageManager::EPage::USER_LOGIN);
		m_pages.emplace("register",	PageManager::EPage::USER_REGISTER);
	}
}

void WebPageStateApi::SetPage()
{
	auto it = m_pages.find(m_command);
	if (it != m_pages.end())
		m_context->SetPage(it->second);
	else
	{
		m_context->SetPage(m_context->GetHomePage());
		Poco::Util::Application::instance().logger().error("Invalid PageController command: %s", Poco::Any(m_command));
	}
}
