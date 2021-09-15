#ifndef IRRIGATIONRECORD_H
#define IRRIGATIONRECORD_H

#include <string>
#include <Poco/DateTime.h>
#include "Common/JsonObject.h"
#include "Common/SqlObject.h"

class IrrigationRecord : public JsonObject, public SqlObject
{
public:
	enum class Decission
	{
		NONE,
		IRRIGATE,
		DRAIN
	};

	using Tuple = Poco::Tuple<int, int, short, short, short, std::string>;

	IrrigationRecord() = default;
	explicit IrrigationRecord(int id);
	IrrigationRecord(int fieldId, short humidity, short decission, short count);
	explicit IrrigationRecord(const Tuple &record);
	explicit IrrigationRecord(Poco::JSON::Object::Ptr json);

	Poco::DateTime GetDate() const;

	short GetCount() const noexcept { return count_; }
	short GetDecission() const noexcept { return decission_; }
	int GetFieldId() const noexcept { return fieldId_; }
	short GetHumidity() const noexcept { return humidity_; }
	const std::string &GetTime() const noexcept { return time_; }

private:
	void CreateSqlRecord(Poco::Data::Session sql) override final;
	void ReadSqlRecord(Poco::Data::Session sql) override final;
	void DeleteSqlRecord(Poco::Data::Session sql) override final;

	void LoadFromJson(const Poco::JSON::Object::Ptr object) override final;
	void SaveToJson(Poco::JSON::Object::Ptr object) const override final;

	void UpdateSqlRecord(Poco::Data::Session sql) override final {}

	std::string time_;
	int fieldId_;
	short humidity_;
	short count_;
	short decission_;
};

#endif // IRRIGATIONRECORD_H
