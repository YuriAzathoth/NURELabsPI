#ifndef WEBREQUESTFACTORY_H
#define WEBREQUESTFACTORY_H

#include "BaseRequestFactory.h"

struct WebRequestFactory : public BaseRequestFactory
{
	Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest &request) override final;
};

#endif // WEBREQUESTFACTORY_H
