#include "PCH.h"
#include "API/UserApi.h"
#include "API/CategoryApi.h"
#include "API/ContentApi.h"
#include "API/LangApi.h"
#include "API/ProductApi.h"
#include "API/WebPageStateApi.h"
#include "API/WarehouseApi.h"
#include "Shared/ServerContext.h"
#include "WebPages/WebPage.h"
#include "WebRequestFactory.h"

Poco::Net::HTTPRequestHandler* WebRequestFactory::createRequestHandler(const Poco::Net::HTTPServerRequest &request)
{
	// Page
	if (request.getURI() == "/")
		return new WebPage(m_context);
	// API
	else if (request.getURI().substr(0, 5) == "/page")
		return new WebPageStateApi(m_context, request.getURI().substr(6));
	else if (request.getURI().substr(0, 5) == "/user")
		return new UserApi(m_context, request.getURI().substr(6));
	else if (request.getURI().substr(0, 8) == "/product")
		return new ProductApi(m_context, request.getURI().substr(9));
	else if (request.getURI().substr(0, 10) == "/warehouse")
		return new WarehouseApi(m_context, request.getURI().substr(11));
	else if (request.getURI().substr(0, 9) == "/category")
		return new CategoryApi(m_context, request.getURI().substr(10));
	else if (request.getURI().substr(0, 5) == "/lang")
		return new LangApi(m_context);
	// Content
	return new ContentApi;
}
