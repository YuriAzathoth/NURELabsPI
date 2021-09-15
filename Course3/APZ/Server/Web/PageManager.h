#ifndef PAGEMANAGER_H
#define PAGEMANAGER_H

#include "Web/CookiesManager.h"
#include "Web/ICookieDependentObject.h"

class PageManager : public ICookieDependentObject
{
public:
	enum class EPage
	{
		USER_LOGIN,
		USER_REGISTER,
		USER_EDIT,
		HOME_CLIENT,
		PRODUCT_ADD,
		HOME_ADMIN_WAREHOUSES,
		HOME_ADMIN_CATEGORIES,
		HOME_ADMIN_PRODUCTS,
		HOME_ADMIN_REG_WARE,
		HOME_ADMIN_REG_CAT,
		HOME_ADMIN_ADD_PROD,
		HOME_ADMIN_WARE_STORE,
		HOME_ADMIN_WARE_VIEW
	};

	PageManager(CookiesManager &cookies) : ICookieDependentObject(cookies), m_page(static_cast<EPage>(cookies.GetPage())) {}

	EPage Get() const noexcept { return m_page; }
	void Set(EPage page) noexcept
	{
		m_page = page;
		GetCookies().SetPage(static_cast<int>(page));
	}

	static EPage GetHome(bool is_logged, int role) noexcept;

private:
	EPage m_page;
};

#endif // PAGEMANAGER_H
