#ifndef AGRICULTURE_H
#define AGRICULTURE_H

#include <string>
#include "Common/JsonObject.h"
#include "Common/SqlObject.h"

class Agriculture : public JsonObject, public SqlObject
{
public:
	using Tuple = Poco::Tuple<int, std::string, short, short>;

	Agriculture() = default;
	explicit Agriculture(int id);
	Agriculture(const std::string &name, short humidityMin, short humidityMax);
	Agriculture(int id, const std::string &name, short humidityMin, short humidityMax);
	explicit Agriculture(const Tuple &record);
	explicit Agriculture(const Poco::JSON::Object::Ptr json);

	void SetName(const std::string name) { name_ = name; }
	void SetHumidityMin(short humidityMin) { humidityMin_ = humidityMin; }
	void SetHumidityMax(short humidityMax) { humidityMax_ = humidityMax; }

	const std::string &GetName() const noexcept { return name_; }
	short GetHumidityMin() const noexcept { return humidityMin_; }
	short GetHumidityMax() const noexcept { return humidityMax_; }

private:
	void CreateSqlRecord(Poco::Data::Session sql) override final;
	void ReadSqlRecord(Poco::Data::Session sql) override final;
	void UpdateSqlRecord(Poco::Data::Session sql) override final;
	void DeleteSqlRecord(Poco::Data::Session sql) override final;

	void LoadFromJson(const Poco::JSON::Object::Ptr object) override final;
	void SaveToJson(Poco::JSON::Object::Ptr object) const override final;

	std::string name_;
	short humidityMin_;
	short humidityMax_;
};

#endif // AGRICULTURE_H
