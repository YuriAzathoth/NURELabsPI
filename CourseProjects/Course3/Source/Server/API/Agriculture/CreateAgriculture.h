#ifndef CREATEAGRICULTURE_H
#define CREATEAGRICULTURE_H

#include "API/RequestHandler.h"

class CreateAgriculture : public RequestHandler
{
private:
	std::string ProcessRequest() override final;
	void ValidateData() const override final;
	void LoadFromJson(const Poco::JSON::Object::Ptr object) override final;

	std::string token_;
	std::string name_;
	short humidityMin_;
	short humidityMax_;
};

#endif // CREATEAGRICULTURE_H
