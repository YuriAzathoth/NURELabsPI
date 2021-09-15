#ifndef AGRICULTURETABLE_H
#define AGRICULTURETABLE_H

#include <string>
#include <vector>
#include "Common/JsonObject.h"
#include "Common/SqlObject.h"
#include "Agriculture.h"

class AgricultureTable : public JsonObject, public SqlObject
{
public:
	AgricultureTable();

	size_t GetSize() const noexcept { return table_.size(); }

private:
	void ReadSqlRecord(Poco::Data::Session sql) override final;
	void LoadFromJson(Poco::JSON::Object::Ptr object) override final;
	void SaveToJson(Poco::JSON::Object::Ptr object) const override final;

	void CreateSqlRecord(Poco::Data::Session) override final {}
	void UpdateSqlRecord(Poco::Data::Session) override final {}
	void DeleteSqlRecord(Poco::Data::Session) override final {}

	std::vector<Agriculture> table_;
};

#endif // AGRICULTURETABLE_H
