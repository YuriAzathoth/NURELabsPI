#include "Common/ServerException.h"
#include "Model/Field.h"
#include "Model/User.h"
#include "Task.h"

#define SQL_CREATE R"(INSERT INTO "tasks"("field_id", "employee_id", "status") VALUES(?, ?, ?) RETURNING "id")"
#define SQL_READ R"(SELECT "id", "status" FROM "tasks" WHERE "employee_id" = ? AND "field_id" = ?)"
#define SQL_READ_ID R"(SELECT "field_id", "employee_id", "status" FROM "tasks" WHERE "id" = ?)"
#define SQL_UPDATE R"(UPDATE "tasks" SET "status" = ? WHERE "id" = ?)"
#define SQL_DELETE R"(DELETE FROM "tasks" WHERE "id" = ?)"

using namespace Poco::Data::Keywords;

Task::Task(int id) :
	SqlObject(id),
	fieldId_(0),
	employeeId_(0)
{
	ReadSql();
}

Task::Task(int fieldId, int employeeId) :
	fieldId_(fieldId),
	employeeId_(employeeId)
{
	ReadSql();
}

Task::Task(int fieldId, int employeeId, Status status) :
	fieldId_(fieldId),
	employeeId_(employeeId),
	status_(static_cast<short>(status))
{
}

Task::Task(int id, int fieldId, int employeeId, Status status) :
	SqlObject(id),
	fieldId_(fieldId),
	employeeId_(employeeId),
	status_(static_cast<short>(status))
{
}

Task::Task(const Tuple &record) :
	SqlObject(record.get<0>()),
	fieldId_(record.get<1>()),
	employeeId_(record.get<2>()),
	status_(record.get<3>())
{
}

Task::Task(const Poco::JSON::Object::Ptr json)
{
	FromJsonObject(json);
}

void Task::CreateSqlRecord(Poco::Data::Session sql)
{
	sql << SQL_CREATE, use(fieldId_), use(employeeId_), use(status_),
		into(id_), now;
}

void Task::ReadSqlRecord(Poco::Data::Session sql)
{
	if (id_ > 0)
		sql << SQL_READ_ID, use(id_), into(fieldId_), into(employeeId_),
			into(status_), now;
	else if (employeeId_ > 0 && fieldId_ > 0)
		sql << SQL_READ, use(employeeId_), use(fieldId_), into(id_),
			into(status_), now;
}

void Task::UpdateSqlRecord(Poco::Data::Session sql)
{
	sql << SQL_UPDATE, use(status_), use(id_), now;
}

void Task::DeleteSqlRecord(Poco::Data::Session sql)
{
	sql << SQL_DELETE, use(id_), now;
}

void Task::LoadFromJson(const Poco::JSON::Object::Ptr object)
{
	const User employee(object->getObject("employee"));
	const Field field(object->getObject("field"));

	employeeId_ = employee.GetId();
	fieldId_	= field.GetId();
	status_		= object->getValue<short>("status");
}

void Task::SaveToJson(Poco::JSON::Object::Ptr object) const
{
	const User employee(employeeId_);
	const Field field(fieldId_);

	object->set("employee",	employee.ToJsonObject());
	object->set("field",	field.ToJsonObject());
	object->set("status",	status_);
}
