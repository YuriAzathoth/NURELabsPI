#ifndef MOBILEAPI_H
#define MOBILEAPI_H

#include "Shared/IObject.h"

class MobileApi : public Poco::Net::HTTPRequestHandler, public IObject
{
public:
	using IObject::IObject;
	void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) override final;

private:
	void Authorize		(Poco::Net::HTTPServerResponse &response, const Poco::Net::HTMLForm &form);
	void GetProducts	(Poco::Net::HTTPServerResponse &response, const Poco::Net::HTMLForm &form);
	void AddProduct		(Poco::Net::HTTPServerResponse &response, const Poco::Net::HTMLForm &form);
	void RemoveProduct	(Poco::Net::HTTPServerResponse &response, const Poco::Net::HTMLForm &form);
	void GetCategories	(Poco::Net::HTTPServerResponse &response);
};

#endif // MOBILEAPI_H
