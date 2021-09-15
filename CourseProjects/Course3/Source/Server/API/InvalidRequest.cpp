#include <Poco/Logger.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Util/Application.h>
#include "Model/ResponseCode.h"
#include "InvalidRequest.h"

void InvalidRequest::handleRequest(Poco::Net::HTTPServerRequest  &request,
								   Poco::Net::HTTPServerResponse &response)
{
	Poco::Util::Application::instance().logger().information("INVALID HANDLER: %s", request.getURI());

	response.setStatus(Poco::Net::HTTPResponse::HTTP_NOT_FOUND);
	response.setContentType("application/json");
	response.send() << ResponseCode::GetJson(ResponseCode::Code::INVALID_REQUEST, "Invalid request.");
}
