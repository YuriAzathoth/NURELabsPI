#include <Poco/DateTimeParser.h>
#include "IrrigationRecord.h"

#define SQL_CREATE R"(INSERT INTO "irrigation_log"("field_id", "humidity", "decission", "count") VALUES (?, ?, ?, ?) RETURNING "id", "logtime")"
#define SQL_READ R"(SELECT "field_id", "humidity", "decission", "count", "logtime" FROM "irrigation_log" WHERE "id" = ?)"
#define SQL_DELETE R"(DELETE FROM "irrigation_log" WHERE "id" = ?)"

using namespace Poco::Data::Keywords;

IrrigationRecord::IrrigationRecord(int id) :
	SqlObject(id)
{
	ReadSql();
}

IrrigationRecord::IrrigationRecord(int fieldId,
								   short humidity,
								   short decission,
								   short count) :
	humidity_(humidity),
	fieldId_(fieldId),
	decission_(decission),
	count_(count)
{
}

IrrigationRecord::IrrigationRecord(const Tuple &record) :
	SqlObject(record.get<0>()),
	time_(record.get<5>()),
	humidity_(record.get<2>()),
	fieldId_(record.get<1>()),
	decission_(record.get<3>()),
	count_(record.get<4>())
{
}

IrrigationRecord::IrrigationRecord(Poco::JSON::Object::Ptr json)
{
	FromJsonObject(json);
}

Poco::DateTime IrrigationRecord::GetDate() const
{
	int zone = 0;
	Poco::DateTime date;
	Poco::DateTimeParser::parse("%YYYY-%mm-%dd %H:%M:%S.%F", time_, date, zone);
	return date;
}

void IrrigationRecord::CreateSqlRecord(Poco::Data::Session sql)
{
	sql << SQL_CREATE, use(fieldId_), use(humidity_), use(decission_),
		use(count_), into(id_), into(time_), now;
}

void IrrigationRecord::ReadSqlRecord(Poco::Data::Session sql)
{
	sql << SQL_READ, use(id_), into(fieldId_), into(humidity_),
		into(decission_), into(count_), into(time_), now;
}

void IrrigationRecord::DeleteSqlRecord(Poco::Data::Session sql)
{
	sql << SQL_DELETE, use(id_), now;
}

void IrrigationRecord::LoadFromJson(const Poco::JSON::Object::Ptr object)
{
	count_		= object->getValue<short>("count");
	decission_	= object->getValue<short>("decission");
	fieldId_	= object->getValue<int>("field_id");
	humidity_	= object->getValue<short>("humidity");
	id_			= object->getValue<int>("id");
	time_		= object->getValue<std::string>("time");
}

void IrrigationRecord::SaveToJson(Poco::JSON::Object::Ptr object) const
{
	object->set("count",		count_);
	object->set("decission",	decission_);
	object->set("field_id",		fieldId_);
	object->set("humidity",		humidity_);
	object->set("id",			id_);
	object->set("time",			time_);
}
