#ifndef DOMEASUREMENT_H
#define DOMEASUREMENT_H

#include "API/RequestHandler.h"

class DoMeasurement : public RequestHandler
{
private:
	std::string ProcessRequest() override final;
	void ValidateData() const override final;
	void LoadFromJson(const Poco::JSON::Object::Ptr object) override final;

	std::string token_;
	int id_;
	short humidity_;
};

#endif // DOMEASUREMENT_H
