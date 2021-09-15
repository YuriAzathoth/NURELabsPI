#ifndef MOBREQUESTFACTORY_H
#define MOBREQUESTFACTORY_H

#include "BaseRequestFactory.h"

struct MobRequestFactory : public BaseRequestFactory
{
	Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest &request) override final;
};

#endif // MOBREQUESTFACTORY_H
