#include "PCH.h"
#include "API/IoTApi.h"
#include "API/MobileApi.h"
#include "Shared/ServerContext.h"
#include "MobRequestFactory.h"

Poco::Net::HTTPRequestHandler* MobRequestFactory::createRequestHandler(const Poco::Net::HTTPServerRequest &request)
{
	if (request.getURI().substr(0, 4) == "/iot")
		return new IoTApi(m_context);
	else if (request.getURI().substr(0, 7) == "/mobile")
		return new MobileApi(m_context);
	else
		return nullptr;
}
