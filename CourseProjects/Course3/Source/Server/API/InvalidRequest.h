#ifndef INVALIDREQUEST_H
#define INVALIDREQUEST_H

#include <boost/noncopyable.hpp>
#include <Poco/Net/HTTPRequestHandler.h>

class InvalidRequest :
	public Poco::Net::HTTPRequestHandler,
	private boost::noncopyable
{
private:
	void handleRequest(Poco::Net::HTTPServerRequest  &request,
					   Poco::Net::HTTPServerResponse &response) override final;
};

#endif // INVALIDREQUEST_H
