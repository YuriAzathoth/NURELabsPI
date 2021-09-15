#ifndef REQUESTFACTORY_H
#define REQUESTFACTORY_H

#include <boost/config.hpp>
#include <Poco/Net/HTTPRequestHandlerFactory.h>

struct BOOST_SYMBOL_VISIBLE RequestFactory :
	public Poco::Net::HTTPRequestHandlerFactory
{
	Poco::Net::HTTPRequestHandler*
	createRequestHandler(const Poco::Net::HTTPServerRequest &request) override final;
};

#endif // REQUESTFACTORY_H
