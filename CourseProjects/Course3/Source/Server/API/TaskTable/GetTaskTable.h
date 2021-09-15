#ifndef GETTASKTABLE_H
#define GETTASKTABLE_H

#include "API/RequestHandler.h"

class GetTaskTable : public RequestHandler
{
private:
	std::string ProcessRequest() override final;
	void LoadFromJson(const Poco::JSON::Object::Ptr object) override final;

	std::string token_;
};

#endif // GETTASKTABLE_H
