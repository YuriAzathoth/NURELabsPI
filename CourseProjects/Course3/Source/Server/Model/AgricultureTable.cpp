#include "AgricultureTable.h"

#define SQL_READ R"(SELECT "id", "name", "humidity_min", "humidity_max" FROM "agricultures")"

using namespace Poco::Data::Keywords;

AgricultureTable::AgricultureTable()
{
	ReadSql();
}

void AgricultureTable::ReadSqlRecord(Poco::Data::Session sql)
{
	std::vector<Agriculture::Tuple> agricultures;
	sql << SQL_READ, into(agricultures), now;
	table_.reserve(agricultures.size());
	for (const auto &record : agricultures)
		table_.emplace_back(record);
}

void AgricultureTable::LoadFromJson(Poco::JSON::Object::Ptr object)
{
	const Poco::JSON::Array::Ptr jsonTable = object->getArray("table");
	table_.clear();
	for (const auto &jsonObject : *jsonTable)
		table_.emplace_back(jsonObject.extract<Poco::JSON::Object::Ptr>());
}

void AgricultureTable::SaveToJson(Poco::JSON::Object::Ptr object) const
{
	Poco::JSON::Array::Ptr jsonTable = new Poco::JSON::Array;
	for (const auto &record : table_)
		jsonTable->add(record.ToJsonObject());
	object->set("table", jsonTable);
}
