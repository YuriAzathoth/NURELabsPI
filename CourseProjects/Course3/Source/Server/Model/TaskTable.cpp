#include <algorithm>
#include "Common/ServerException.h"
#include "Model/FieldTable.h"
#include "Model/UsersTable.h"
#include "TaskTable.h"

#define SQL_READ R"(SELECT "id", "field_id", "employee_id", "status" FROM "tasks" WHERE "employee_id" = ?)"
#define SQL_READ_ALL R"(SELECT "id", "field_id", "employee_id", "status" FROM "tasks")"

using namespace Poco::Data::Keywords;

TaskTable::TaskTable(int userId) :
	userId_(userId)
{
	ReadSql();
}

void TaskTable::CompleteTask(int fieldId)
{
	auto taskIterator =
	std::find_if(table_.begin(), table_.end(),
	[fieldId](const Task &task) -> bool
	{
		return task.GetFieldId() == fieldId;
	});

	if (taskIterator == table_.end())
		return;

	Task &task = *taskIterator;
	task.SetStatus(Task::Status::DONE);
	task.UpdateSql();
}

void TaskTable::CreateSqlRecord(Poco::Data::Session)
{
	FieldTable fields(-1);
	UsersTable employees(User::Role::EMPLOYEE);

	if (!fields.GetSize())
		throw ServerException(ServerException::Code::INTERNAL_ERROR, "No fields.");
	if (!employees.GetSize())
		throw ServerException(ServerException::Code::INTERNAL_ERROR, "No employees.");

	const size_t fieldsForEmployee = fields.GetSize() / employees.GetSize();
	auto fieldIterator = fields.GetTable().cbegin();

	table_.reserve(fields.GetSize());
	for (const User employee : employees.GetTable())
		for (size_t i = 0; i < fieldsForEmployee; ++i)
		{
			table_.emplace_back(fieldIterator->GetId(),
								employee.GetId(),
								Task::Status::ACTIVE);
			table_.back().CreateSql();

			if (fieldIterator == fields.GetTable().cend())
				return;

			++fieldIterator;
		}
}

void TaskTable::ReadSqlRecord(Poco::Data::Session sql)
{
	std::vector<Task::Tuple> tasks;
	if (userId_ == -1)
		sql << SQL_READ_ALL, into(tasks), now;
	else
		sql << SQL_READ, use(userId_), into(tasks), now;

	table_.reserve(tasks.size());
	for (const auto &record : tasks)
		table_.emplace_back(record);
}

void TaskTable::LoadFromJson(Poco::JSON::Object::Ptr object)
{
	userId_ = object->getValue<int>("user_id");
	const Poco::JSON::Array::Ptr jsonTable = object->getArray("table");
	table_.clear();
	for (const auto &jsonObject : *jsonTable)
		table_.emplace_back(jsonObject.extract<Poco::JSON::Object::Ptr>());
}

void TaskTable::SaveToJson(Poco::JSON::Object::Ptr object) const
{
	object->set("user_id", userId_);
	Poco::JSON::Array::Ptr jsonTable = new Poco::JSON::Array;
	for (const auto &record : table_)
		jsonTable->add(record.ToJsonObject());
	object->set("table", jsonTable);
}
