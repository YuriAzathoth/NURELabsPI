#ifndef UPDATEAGRICULTURE_H
#define UPDATEAGRICULTURE_H

#include "API/RequestHandler.h"

class UpdateAgriculture : public RequestHandler
{
private:
	std::string ProcessRequest() override final;
	void ValidateData() const override final;
	void LoadFromJson(const Poco::JSON::Object::Ptr object) override final;

	std::string token_;
	std::string name_;
	int id_;
	short humidityMin_;
	short humidityMax_;
};

#endif // UPDATEAGRICULTURE_H
