#include "Agriculture.h"
#include "Common/ServerException.h"

#define SQL_CREATE R"(INSERT INTO "agricultures"("name", "humidity_min", "humidity_max") VALUES(?, ?, ?) RETURNING "id")"
#define SQL_READ R"(SELECT "name", "humidity_min", "humidity_max" FROM "agricultures" WHERE "id" = ?)"
#define SQL_UPDATE R"(UPDATE "agricultures" SET "name" = ?, "humidity_min" = ?, "humidity_max" = ? WHERE "id" = ?)"
#define SQL_DELETE R"(DELETE FROM "agricultures" WHERE "id" = ?)"

using namespace Poco::Data::Keywords;

Agriculture::Agriculture(int id) :
	SqlObject(id)
{
	ReadSql();
}

Agriculture::Agriculture(const std::string &name,
						 short humidityMin,
						 short humidityMax) :
	name_(name),
	humidityMin_(humidityMin),
	humidityMax_(humidityMax)
{
}

Agriculture::Agriculture(int id,
						 const std::string &name,
						 short humidityMin,
						 short humidityMax) :
	SqlObject(id),
	name_(name),
	humidityMin_(humidityMin),
	humidityMax_(humidityMax)
{
}

Agriculture::Agriculture(const Tuple &record) :
	SqlObject(record.get<0>()),
	name_(record.get<1>()),
	humidityMin_(record.get<2>()),
	humidityMax_(record.get<3>())
{
}

Agriculture::Agriculture(const Poco::JSON::Object::Ptr json)
{
	FromJsonObject(json);
}

void Agriculture::CreateSqlRecord(Poco::Data::Session sql)
{
	sql << SQL_CREATE, use(name_), use(humidityMin_), use(humidityMax_),
		into(id_), now;
}

void Agriculture::ReadSqlRecord(Poco::Data::Session sql)
{
	sql << SQL_READ, use(id_), into(name_), into(humidityMin_),
		into(humidityMax_), now;

	if (name_.empty())
		throw ServerException(ServerException::Code::INVALID_ID,
							  "Invalid sql record id.");
}

void Agriculture::UpdateSqlRecord(Poco::Data::Session sql)
{
	sql << SQL_UPDATE, use(name_), use(humidityMin_), use(humidityMax_),
		use(id_), now;
}

void Agriculture::DeleteSqlRecord(Poco::Data::Session sql)
{
	sql << SQL_DELETE, use(id_), now;
}

void Agriculture::LoadFromJson(const Poco::JSON::Object::Ptr object)
{
	humidityMax_	= object->getValue<float>("humidity_max");
	humidityMin_	= object->getValue<float>("humidity_min");
	id_				= object->getValue<int>("id");
	name_			= object->getValue<std::string>("name");
}

void Agriculture::SaveToJson(Poco::JSON::Object::Ptr object) const
{
	object->set("humidity_max",	humidityMax_);
	object->set("humidity_min",	humidityMin_);
	object->set("name",			name_);
	object->set("id",			id_);
}
