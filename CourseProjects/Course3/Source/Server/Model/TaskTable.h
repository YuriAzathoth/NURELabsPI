#ifndef TASKTABLE_H
#define TASKTABLE_H

#include <string>
#include <vector>
#include "Common/JsonObject.h"
#include "Common/SqlObject.h"
#include "Task.h"

class TaskTable : public JsonObject, public SqlObject
{
public:
	TaskTable() = default;
	explicit TaskTable(int userId);

	void CompleteTask(int fieldId);

	const std::vector<Task> &GetTable() const noexcept { return table_; }
	size_t GetSize() const noexcept { return table_.size(); }

private:
	void CreateSqlRecord(Poco::Data::Session) override final;
	void ReadSqlRecord(Poco::Data::Session sql) override final;
	void LoadFromJson(Poco::JSON::Object::Ptr object) override final;
	void SaveToJson(Poco::JSON::Object::Ptr object) const override final;

	void UpdateSqlRecord(Poco::Data::Session) override final {}
	void DeleteSqlRecord(Poco::Data::Session) override final {}

	std::vector<Task> table_;
	int userId_;
};

#endif // TASKTABLE_H
