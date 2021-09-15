#ifndef BASEREQUESTFACTORY_H
#define BASEREQUESTFACTORY_H

class ServerContext;

class BaseRequestFactory : public Poco::Net::HTTPRequestHandlerFactory
{
public:
	BaseRequestFactory();
	virtual ~BaseRequestFactory();
protected:
	ServerContext* m_context;
};

#endif // BASEREQUESTFACTORY_H
