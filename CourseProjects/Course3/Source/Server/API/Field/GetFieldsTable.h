#ifndef GETFIELDSTABLE_H
#define GETFIELDSTABLE_H

#include "API/RequestHandler.h"

class GetFieldsTable : public RequestHandler
{
private:
	std::string ProcessRequest() override final;
	void LoadFromJson(const Poco::JSON::Object::Ptr object) override final;

	std::string token_;
};

#endif // GETFIELDSTABLE_H
