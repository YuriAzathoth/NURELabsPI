#ifndef IOTAPI_H
#define IOTAPI_H

#include "BaseApi.h"

class IoTApi : public Poco::Net::HTTPRequestHandler, public IObject
{
public:
	using IObject::IObject;
	void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) override final;
};

#endif // IOTAPI_H
