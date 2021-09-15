#include "PCH.h"
#include "Shared/ServerContext.h"
#include "Web/CookiesManager.h"
#include "Utility.h"
#include "WarehouseTable.h"

using namespace Poco::Data::Keywords;

WarehouseTable::WarehouseTable(ServerContext* global_context, CookiesManager &cookies) :
	IObject(global_context),
	ICookieDependentObject(cookies)
{
	Warehouse warehouse;

	try
	{
		Poco::Data::Session db_session = GetContext()->GetDb().NewSession();
		Poco::Data::Statement db_select(db_session);
		db_select << R"(SELECT * FROM "LOAD_WAREHOUSES"())",
				  into(warehouse.id),
				  into(warehouse.address),
				  into(warehouse.tempo),
				  into(warehouse.humidity),
				  into(warehouse.space_busy),
				  into(warehouse.space_free),
				  into(warehouse.cost),
				  into(warehouse.ip),
				  range(0, 1);

		while (!db_select.done())
			if (db_select.execute())
			{
				ToUtf8(warehouse.address);
				m_warehouses.push_back(warehouse);
			}
	}
	catch (Poco::Exception &e)
	{
		Poco::Util::Application::instance().logger().error(e.displayText());
	}
}

bool WarehouseTable::Register(std::string address, uint16_t space, uint16_t cost, const std::string &ip)
{
	FromUtf8(address);
	uint8_t result = 0;
	try
	{
		GetContext()->GetDb().NewSession() << R"(SELECT "REGISTER_WAREHOUSE"(?, ?, ?, ?))",
				   bind(address), use(space), use(cost), bind(ip), into(result), now;
		if (result)
			GetCookies().SetError("error.invip");
	}
	catch (Poco::Exception &e)
	{
		Poco::Util::Application::instance().logger().error(e.displayText());
	}
	return result == 0;
}

void WarehouseTable::Remove(uint32_t id)
{
	try
	{
		GetContext()->GetDb().NewSession() << R"(CALL "DELETE_WAREHOUSE"(?))", use(id), now;
	}
	catch (Poco::Exception &e)
	{
		Poco::Util::Application::instance().logger().error(e.displayText());
	}
}
