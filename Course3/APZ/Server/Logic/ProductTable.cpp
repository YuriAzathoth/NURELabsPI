#include "PCH.h"
#include "Web/Localization.h"
#include "Shared/ServerContext.h"
#include "ProductTable.h"
#include "Utility.h"

using namespace Poco::Data::Keywords;

void ProductTable::Calc(std::string cat_name, uint16_t count, std::string user_token)
{
	FromUtf8(cat_name);
	try
	{
		int32_t ware_id;
		GetContext()->GetDb().NewSession() << R"(SELECT "CALCULATE_BEST_WAREHOUSE"(?))", use(cat_name), into(ware_id), now;
		Create(ware_id, cat_name, count, user_token);
	}
	catch (Poco::Exception &e)
	{
		Poco::Util::Application::instance().logger().error(e.displayText());
	}
}

void ProductTable::Create(std::string ware_name, std::string cat_name, uint16_t count, std::string user_token)
{
	FromUtf8(ware_name);
	FromUtf8(cat_name);
	uint32_t ware_id;
	try
	{
		GetContext()->GetDb().NewSession() << R"(SELECT "warehouse_id" FROM "warehouses" WHERE "warehouse_address" = ?)",
				   use(ware_name), into(ware_id), now;
		Create(ware_id, cat_name, count, user_token);
	}
	catch (Poco::Exception &e)
	{
		Poco::Util::Application::instance().logger().error(e.displayText());
	}
}

void ProductTable::Create(uint32_t ware_id, std::string cat_name, uint16_t count, std::string user_token)
{
	GetContext()->GetDb().NewSession() << R"(CALL "STORE_PRODUCT"(?, ?, ?, ?))",
			   use(ware_id), use(cat_name), use(user_token), use(count), now;
}

void ProductTable::Load()
{
	LoadData(R"(SELECT * FROM "storage_data")");
}

void ProductTable::Load(EScope scope, uint32_t id)
{
	if (scope == EScope::USER)
		LoadData(R"(SELECT * FROM "storage_data" WHERE "user_id" = )" + std::to_string(id));
	else if (scope == EScope::WAREHOUSE)
		LoadData(R"(SELECT * FROM "storage_data" WHERE "warehouse_id" = )" + std::to_string(id));
}

void ProductTable::Remove(uint32_t id)
{
	try
	{
		GetContext()->GetDb().NewSession() << R"(CALL "REMOVE_PRODUCT"(?))", use(id), now;
	}
	catch (Poco::Exception &e)
	{
		Poco::Util::Application::instance().logger().error(e.displayText());
	}
}

void ProductTable::LoadData(const std::string &statement)
{
	if (!m_products.empty())
		m_products.clear();

	try
	{
		Poco::Data::Session		db_session = GetContext()->GetDb().NewSession();
		Poco::Data::Statement	db_select(db_session);

		Product product;
		db_select << statement,
				  into(product.id),
				  into(product.name),
				  into(product.count),
				  into(product.space),
				  into(product.date_begin),
				  into(product.date_end),
				  into(product.address),
				  into(product.login),
				  range(0, 1);

		while (!db_select.done())
			if (db_select.execute())
				m_products.push_back(product);
	}
	catch (Poco::Exception &e)
	{
		Poco::Util::Application::instance().logger().error(e.displayText());
	}
}
