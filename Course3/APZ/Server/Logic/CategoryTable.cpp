#include "PCH.h"
#include "Shared/ServerContext.h"
#include "CategoryTable.h"
#include "Utility.h"

using namespace Poco::Data::Keywords;

CategoryTable::CategoryTable(ServerContext* global_context) : IObject(global_context)
{
	Category category;
	try
	{
		Poco::Data::Session db_session = GetContext()->GetDb().NewSession();
		Poco::Data::Statement db_select(db_session);
		db_select << R"(SELECT * FROM "LOAD_CATEGORIES"())",
				  into(category.id),
				  into(category.name),
				  into(category.tmin),
				  into(category.tmax),
				  into(category.hmin),
				  into(category.hmax),
				  into(category.space),
				  range(0, 1);

		while (!db_select.done())
			if (db_select.execute())
			{
				ToUtf8(category.name);
				m_categories.push_back(category);
			}
	}
	catch (Poco::Exception &e)
	{
		Poco::Util::Application::instance().logger().error(e.displayText());
	}
}

void CategoryTable::Register(std::string name, float tmin, float tmax, uint8_t hmin, uint8_t hmax, uint16_t space)
{
	FromUtf8(name);
	try
	{
		GetContext()->GetDb().NewSession() << R"(CALL "REGISTER_CATEGORY"(?, ?, ?, ?, ?, ?))",
				   use(name), use(tmin), use(tmax), use(hmin), use(hmax), use(space), now;
	}
	catch (Poco::Exception &e)
	{
		Poco::Util::Application::instance().logger().error(e.displayText());
	}
}

void CategoryTable::Remove(uint32_t id)
{
	try
	{
		GetContext()->GetDb().NewSession() << R"(CALL "DELETE_CATEGORY"(?))", use(id), now;
	}
	catch (Poco::Exception &e)
	{
		Poco::Util::Application::instance().logger().error(e.displayText());
	}
}
