#include "PCH.h"
#include "Logic/WarehouseTable.h"
#include "WarehouseApi.h"

void WarehouseApi::HandleControl()
{
	if (m_context->GetUser().GetRole() != User::ERole::ADMINISTRATOR)
		return;

	WarehouseTable &waremgr = m_context->GetWarehouseTable();
	if (IsCommand("create"))
	{
		if (waremgr.Register(GetFormData("address"), std::stoi(GetFormData("space")), std::stoi(GetFormData("cost")), GetFormData("ip")))
			m_context->SetPage(PageManager::EPage::HOME_ADMIN_WAREHOUSES);
	}
	else if (IsCommand("remove"))
		waremgr.Remove(std::stoi(GetFormData("id")));
	else
		Poco::Util::Application::instance().logger().error("Invalid WarehouseController command");
}
