#ifndef FIELDTABLE_H
#define FIELDTABLE_H

#include <string>
#include <vector>
#include "Common/JsonObject.h"
#include "Common/SqlObject.h"
#include "Field.h"
#include "Model/User.h"

class FieldTable : public JsonObject, public SqlObject
{
public:
	FieldTable(int userId);

	const std::vector<Field> &GetTable() const noexcept { return table_; }
	size_t GetSize() const noexcept { return table_.size(); }

private:
	void ReadSqlRecord(Poco::Data::Session sql) override final;
	void LoadFromJson(Poco::JSON::Object::Ptr object) override final;
	void SaveToJson(Poco::JSON::Object::Ptr object) const override final;

	void CreateSqlRecord(Poco::Data::Session) override final {}
	void UpdateSqlRecord(Poco::Data::Session sql) override final {}
	void DeleteSqlRecord(Poco::Data::Session) override final {}

	std::vector<Field> table_;
	int userId_;
};

#endif // FIELDTABLE_H
