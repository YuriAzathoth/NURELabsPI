#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include <string>
#include <boost/noncopyable.hpp>
#include <Poco/Net/HTTPRequestHandler.h>
#include "Common/JsonReadObject.h"

class RequestHandler :
	public Poco::Net::HTTPRequestHandler,
	private JsonReadObject,
	private boost::noncopyable
{
public:
	void handleRequest(Poco::Net::HTTPServerRequest  &request,
					   Poco::Net::HTTPServerResponse &response) override final;

protected:
	RequestHandler() = default;
	virtual ~RequestHandler() = default;

private:
	virtual std::string ProcessRequest() = 0;
	virtual void ValidateData() const {};
};

#endif // REQUESTHANDLER_H
