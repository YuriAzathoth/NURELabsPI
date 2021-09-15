#include <utility>
#include <Poco/Data/Statement.h>
#include <Poco/JSON/Array.h>
#include <Poco/Tuple.h>
#include "Field.h"

#define SQL_CREATE R"(INSERT INTO "fields"("cadastral", "agriculture_id", "user_id", "area") VALUES(?, ?, ?, ?) RETURNING "id")"
#define SQL_READ R"(SELECT "cadastral", "agriculture_id", "user_id", "area" FROM "fields" WHERE "id" = ?)"
#define SQL_UPDATE R"(UPDATE "fields" SET "agriculture_id" = ?, "area" = ? WHERE "id" = ?)"
#define SQL_DELETE R"(DELETE FROM "fields" WHERE "id" = ?)"

#define SQL_RECORDS_GET R"(SELECT "id", "field_id", "humidity", "decission", "count", "logtime" FROM "irrigation_log" WHERE "field_id" = ?)"

using namespace Poco::Data::Keywords;

Field::Field(int id) :
	SqlObject(id)
{
	ReadSql();
}

Field::Field(std::string cadastral, int agricultureId, int userId, short area) :
	cadastral_(cadastral),
	agriculture_(std::make_unique<Agriculture>(agricultureId)),
	userId_(userId),
	area_(area)
{
}

Field::Field(int id,
			 std::string cadastral,
			 int agricultureId,
			 int userId,
			 short area) :
	SqlObject(id),
	cadastral_(cadastral),
	agriculture_(std::make_unique<Agriculture>(agricultureId)),
	userId_(userId),
	area_(area)
{
}

Field::Field(const Poco::JSON::Object::Ptr json)
{
	FromJsonObject(json);
}

const IrrigationRecord &Field::DoMeasurement(short humidity)
{
	const short min = agriculture_->GetHumidityMin();
	const short max = agriculture_->GetHumidityMax();
	const short mid = (min + max) / 2.0f;
	IrrigationRecord::Decission decission = IrrigationRecord::Decission::NONE;
	unsigned short count = 0;

	if (humidity < min)
		decission = IrrigationRecord::Decission::IRRIGATE;
	else if (humidity > max)
		decission = IrrigationRecord::Decission::DRAIN;

	if (decission != IrrigationRecord::Decission::NONE)
		count = static_cast<unsigned short>((mid - humidity) * area_);

	IrrigationRecord record(GetId(), humidity, static_cast<short>(decission), count);
	record.CreateSql();
	record.ReadSql();
	return log_.emplace(record.GetTime(), record)->second;
}

void Field::CreateSqlRecord(Poco::Data::Session sql)
{
	sql << SQL_CREATE, use(cadastral_), bind(agriculture_->GetId()),
		use(userId_), use(area_), into(id_), now;
}

void Field::ReadSqlRecord(Poco::Data::Session sql)
{
	int agricultureId;

	sql << SQL_READ, use(id_), into(cadastral_), into(agricultureId),
		into(userId_), into(area_), now;

	agriculture_ = std::make_unique<Agriculture>(agricultureId);

	std::vector<IrrigationRecord::Tuple> irrigationRecords;
	sql << SQL_RECORDS_GET, use(id_), into(irrigationRecords), now;
	for (const auto &record : irrigationRecords)
		log_.emplace(record.get<5>(), record);
}

void Field::UpdateSqlRecord(Poco::Data::Session sql)
{
	sql << SQL_UPDATE, bind(agriculture_->GetId()), use(area_), use(id_), now;
}

void Field::DeleteSqlRecord(Poco::Data::Session sql)
{
	sql << SQL_DELETE, use(id_), now;
}

void Field::LoadFromJson(const Poco::JSON::Object::Ptr object)
{
	area_		= object->getValue<short>("area");
	cadastral_	= object->getValue<std::string>("cadastral");
	id_			= object->getValue<int>("id");
	userId_		= object->getValue<int>("user_id");

	agriculture_ = std::make_unique<Agriculture>(object->getObject("agriculture"));

	Poco::JSON::Array::Ptr irrigationLog = object->getArray("irrlog");
	for (unsigned i = 0; i < static_cast<unsigned>(irrigationLog->size()); ++i)
	{
		IrrigationRecord record(irrigationLog->getObject(i));
		log_.emplace(record.GetTime(), record);
	}
}

void Field::SaveToJson(Poco::JSON::Object::Ptr object) const
{
	Poco::JSON::Array::Ptr irrigationLog = new Poco::JSON::Array;
	for (const auto &record : log_)
		irrigationLog->add(record.second.ToJsonObject());

	object->set("agriculture",	agriculture_->ToJsonObject());
	object->set("area",			area_);
	object->set("cadastral",	cadastral_);
	object->set("id",			id_);
	object->set("irrlog",		irrigationLog);
	object->set("user_id",		userId_);
}
