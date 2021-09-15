#ifndef GENERATETASKTABLE_H
#define GENERATETASKTABLE_H

#include "API/RequestHandler.h"

class GenerateTaskTable : public RequestHandler
{
private:
	std::string ProcessRequest() override final;
	void LoadFromJson(const Poco::JSON::Object::Ptr object) override final;

	std::string token_;
};

#endif // GENERATETASKTABLE_H
