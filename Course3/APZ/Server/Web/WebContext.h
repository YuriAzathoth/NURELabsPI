#ifndef WEBCONTEXT_H
#define WEBCONTEXT_H

#include "Logic/CategoryTable.h"
#include "Logic/ProductTable.h"
#include "Logic/WarehouseTable.h"
#include "Shared/IObject.h"
#include "Web/CookiesManager.h"
#include "Web/Localization.h"
#include "Web/PageManager.h"
#include "Web/User.h"

class WebContext : public IObject
{
	struct AdminTables
	{
		AdminTables(ServerContext* context, CookiesManager &cookies) : categories(context), warehouses(context, cookies) {}
		AdminTables(AdminTables&&) noexcept = default;
        CategoryTable	categories;
        WarehouseTable	warehouses;
	};

public:
	WebContext(ServerContext* global_context, const Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) :
		IObject(global_context),
		m_cookies(request, response),
		m_pages(m_cookies),
		m_user(GetContext(), m_cookies, m_pages),
		m_products(global_context, m_cookies),
		m_l10n(GetContext(), m_cookies)
	{
		if (m_cookies.IsError())
			m_error = m_l10n.Get(m_cookies.GetError());
		if (m_user.GetRole() == User::ERole::ADMINISTRATOR)
            m_admin = std::allocate_shared<AdminTables>(boost::pool_allocator<AdminTables>(), global_context, m_cookies);
	}

	Localization	&GetL10n	() noexcept { return m_l10n; }
	User			&GetUser	() noexcept { return m_user; }
	ProductTable	&GetProducts() noexcept { return m_products; }

	bool 				IsError()		const noexcept { return m_error.empty(); }
	PageManager::EPage	GetPage()		const noexcept { return m_pages.Get(); }
	PageManager::EPage	GetHomePage()	const noexcept { return PageManager::GetHome(m_user.IsLoggedIn(), static_cast<int>(m_user.GetRole())); }
	const std::string	&GetError()		const noexcept { return m_error; }

	void SetL10n	(const std::string &lang)	{ m_cookies.SetL10n(lang); }
	void SetPage	(PageManager::EPage page)	{ m_pages.Set(page); }
	void SetError	(const std::string &error)	{ m_cookies.SetError(error); }

	ProductTable	&GetProductTable()		noexcept { return m_products; }
	CategoryTable	&GetCategoryTable()		noexcept { return m_admin->categories; }
	WarehouseTable	&GetWarehouseTable()	noexcept { return m_admin->warehouses; }

private:
	CookiesManager	m_cookies;
	PageManager		m_pages;
	User			m_user;
	ProductTable	m_products;
	Localization	m_l10n;
	std::string		m_error;

	std::shared_ptr<AdminTables> m_admin;
};

#endif // WEBCONTEXT_H
