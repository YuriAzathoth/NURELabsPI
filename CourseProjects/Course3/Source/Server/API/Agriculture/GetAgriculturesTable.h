#ifndef GETAGRICULTURESTABLE_H
#define GETAGRICULTURESTABLE_H

#include "API/RequestHandler.h"

class GetAgriculturesTable : public RequestHandler
{
private:
	std::string ProcessRequest() override final;
	void LoadFromJson(const Poco::JSON::Object::Ptr object) override final {}
};

#endif // GETAGRICULTURESTABLE_H
