#ifndef TASK_H
#define TASK_H

#include <string>
#include "Common/JsonObject.h"
#include "Common/SqlObject.h"

class Task : public JsonObject, public SqlObject
{
public:
	enum class Status { ACTIVE, DONE };

	using Tuple = Poco::Tuple<int, int, int, short>;

	explicit Task(int id);
	Task(int fieldId, int employeeId);
	Task(int fieldId, int employeeId, Status status);
	Task(int id, int fieldId, int employeeId, Status status);
	explicit Task(const Tuple &record);
	explicit Task(const Poco::JSON::Object::Ptr json);

	void SetStatus(Status status) noexcept { status_ = static_cast<short>(status); }

	int GetFieldId() const noexcept { return fieldId_; }
	int GetEmployeeId() const noexcept { return employeeId_; }
	Status GetStatus() const noexcept { return static_cast<Status>(status_); }

private:
	void CreateSqlRecord(Poco::Data::Session sql) override final;
	void ReadSqlRecord(Poco::Data::Session sql) override final;
	void UpdateSqlRecord(Poco::Data::Session sql) override final;
	void DeleteSqlRecord(Poco::Data::Session sql) override final;

	void LoadFromJson(const Poco::JSON::Object::Ptr object) override final;
	void SaveToJson(Poco::JSON::Object::Ptr object) const override final;

	int fieldId_;
	int employeeId_;
	short status_;
};

#endif // TASK_H
