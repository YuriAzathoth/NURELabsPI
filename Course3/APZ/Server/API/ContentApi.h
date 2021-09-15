#ifndef CONTENTAPI_H
#define CONTENTAPI_H

class ContentApi : public Poco::Net::HTTPRequestHandler
{
public:
	void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) override final;
};

#endif // CONTENTAPI_H
