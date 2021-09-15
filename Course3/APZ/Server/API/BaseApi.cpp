#include "PCH.h"
#include "BaseApi.h"

void BaseApi::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
	m_context	= std::make_unique<WebContext>(GetContext(), request, response);
	m_form		= std::make_unique<const Poco::Net::HTMLForm>(request, request.stream());
	HandleControl();
	response.redirect("/");
}
