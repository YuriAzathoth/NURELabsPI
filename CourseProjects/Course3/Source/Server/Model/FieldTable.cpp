#include "FieldTable.h"
#include "User.h"

#define SQL_READ_ALL R"(SELECT "id" FROM "fields")"
#define SQL_READ_OWN R"(SELECT "id" FROM "fields" WHERE "user_id" = ?)"

using namespace Poco::Data::Keywords;

FieldTable::FieldTable(int userId) :
	userId_(userId)
{
	ReadSql();
}

void FieldTable::ReadSqlRecord(Poco::Data::Session sql)
{
	std::vector<int> fields;
	if (userId_ < 0)
		sql << SQL_READ_ALL, into(fields), now;
	else
		sql << SQL_READ_OWN, use(userId_), into(fields), now;
	table_.reserve(fields.size());
	for (int id : fields)
		table_.emplace_back(id);
}

void FieldTable::LoadFromJson(Poco::JSON::Object::Ptr object)
{
	const Poco::JSON::Array::Ptr jsonTable = object->getArray("table");
	table_.clear();
	for (const auto &jsonObject : *jsonTable)
		table_.emplace_back(jsonObject.extract<Poco::JSON::Object::Ptr>());
}

void FieldTable::SaveToJson(Poco::JSON::Object::Ptr object) const
{
	Poco::JSON::Array::Ptr jsonTable = new Poco::JSON::Array;
	for (const auto &record : table_)
		jsonTable->add(record.ToJsonObject());
	object->set("table", jsonTable);
}
