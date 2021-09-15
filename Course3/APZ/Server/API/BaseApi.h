#ifndef BASEAPI_H
#define BASEAPI_H

#include "Web/WebContext.h"
class WebContext;

class BaseApi : public IObject, public Poco::Net::HTTPRequestHandler
{
public:
	BaseApi(ServerContext* context, const std::string &command) :
		IObject(context),
		m_command(std::hash<std::string>{}(command.substr(0, command.find_first_of("?"))))
	{}
	virtual ~BaseApi() {}
	void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) override;

protected:
	const std::string &GetFormData(const std::string &key) const
	{
		return m_form->get(key);
	}
    bool IsCommand(const char* command) const noexcept { return m_command == std::hash<std::string>{}(command); }

	std::unique_ptr<WebContext>	m_context;

private:
	virtual void HandleControl() = 0;

	std::unique_ptr<const Poco::Net::HTMLForm> m_form;
	const size_t m_command;
};

#endif // BASEAPI_H
