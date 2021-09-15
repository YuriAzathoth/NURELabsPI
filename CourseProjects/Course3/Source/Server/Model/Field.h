#ifndef FIELD_H
#define FIELD_H

#include <string>
#include <map>
#include <memory>
#include "Common/JsonObject.h"
#include "Common/SqlObject.h"
#include "Agriculture.h"
#include "IrrigationRecord.h"

class Field : public JsonObject, public SqlObject
{
public:
	using MeasurementLog = std::multimap<std::string, IrrigationRecord>;

	Field() = default;
	explicit Field(int id);
	Field(std::string cadastral, int agricultureId, int userId, short area);
	Field(int id, std::string cadastral, int agricultureId, int userId, short area);
	explicit Field(const Poco::JSON::Object::Ptr json);

	const IrrigationRecord &DoMeasurement(short humidity);

	void SetAgriculture(int id) { agriculture_ = std::make_unique<Agriculture>(id); }
	void SetArea(short area) noexcept { area_ = area; }

	Agriculture* GetAgriculture() const { return agriculture_.get(); }
	int GetAgricultureId() const { return agriculture_->GetId(); }
	short GetArea() const noexcept { return area_; }
	const std::string &GetCadastral() const noexcept { return cadastral_; }
	const MeasurementLog &GetMeasurementLog() const noexcept { return log_; }
	int GetUserId() const noexcept { return userId_; }

private:
	void CreateSqlRecord(Poco::Data::Session sql) override final;
	void ReadSqlRecord(Poco::Data::Session sql) override final;
	void UpdateSqlRecord(Poco::Data::Session sql) override final;
	void DeleteSqlRecord(Poco::Data::Session sql) override final;

	void LoadFromJson(const Poco::JSON::Object::Ptr object) override final;
	void SaveToJson(Poco::JSON::Object::Ptr object) const override final;

	MeasurementLog log_;
	std::string cadastral_;
	std::unique_ptr<Agriculture> agriculture_;
	int userId_;
	short area_;
};

#endif // FIELD_H
