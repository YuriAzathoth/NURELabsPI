#ifndef READFIELD_H
#define READFIELD_H

#include "API/RequestHandler.h"

class ReadField : public RequestHandler
{
private:
	std::string ProcessRequest() override final;
	void ValidateData() const override final;
	void LoadFromJson(const Poco::JSON::Object::Ptr object) override final;

	std::string token_;
	int id_;
};

#endif // READFIELD_H
