#include "PCH.h"
#include "Logic/CategoryTable.h"
#include "CategoryApi.h"

void CategoryApi::HandleControl()
{
	if (m_context->GetUser().GetRole() != User::ERole::ADMINISTRATOR)
		return;

	CategoryTable &table = m_context->GetCategoryTable();
	if (IsCommand("create"))
	{
		table.Register
		(
			GetFormData("name"),
			std::stof(GetFormData("tmin")),
			std::stof(GetFormData("tmax")),
			std::stoi(GetFormData("hmin")),
			std::stoi(GetFormData("hmax")),
			std::stoi(GetFormData("space"))
		);
		m_context->SetPage(PageManager::EPage::HOME_ADMIN_CATEGORIES);
	}
	else if (IsCommand("remove"))
		table.Remove(std::stoi(GetFormData("id")));
	else
		Poco::Util::Application::instance().logger().error("Invalid CategoryController command");
}
