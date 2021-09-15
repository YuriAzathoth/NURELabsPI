#include "PCH.h"
#include "Web/WebContext.h"
#include "ProductApi.h"
#include "Utility.h"

using namespace Poco::Data::Keywords;

void ProductApi::HandleControl()
{
	ProductTable &products = m_context->GetProducts();
	if (IsCommand("add"))
	{
		products.Calc(GetFormData("prod"), std::stoi(GetFormData("count")), m_context->GetUser().GetToken());
		m_context->SetPage(PageManager::EPage::HOME_CLIENT);
	}
	else if (IsCommand("remove"))
		products.Remove(std::stoi(GetFormData("id")));
	else if (IsCommand("admin-add") && m_context->GetUser().GetRole() == User::ERole::ADMINISTRATOR)
	{
		products.Create(GetFormData("ware"), GetFormData("prod"), std::stoi(GetFormData("count")), m_context->GetUser().GetToken());
		m_context->SetPage(PageManager::EPage::HOME_ADMIN_PRODUCTS);
	}
	else
		Poco::Util::Application::instance().logger().error("Invalid ProductController command");
}
