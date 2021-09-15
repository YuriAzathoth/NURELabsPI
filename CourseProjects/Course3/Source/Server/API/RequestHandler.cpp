#include <stdexcept>
#include <Poco/Exception.h>
#include <Poco/Logger.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Util/Application.h>
#include "Common/ServerException.h"
#include "Common/StringUtility.h"
#include "Model/ResponseCode.h"
#include "RequestHandler.h"

void RequestHandler::handleRequest(Poco::Net::HTTPServerRequest  &request,
								   Poco::Net::HTTPServerResponse &response)
{
	Poco::Logger &logger = Poco::Util::Application::instance().logger();

	try
	{
		response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
		response.setContentType("application/json");
		response.set("Access-Control-Allow-Headers", "Content-Type, Access-Control-Allow-Headers, X-Requested-With");
		response.set("Access-Control-Allow-Origin", request.get("Origin", "*"));

		if (request.getContentLength() == -1) // CORS Preflight
			response.send();
		else
		{
			std::string body;
			std::string line;
			while (std::getline(request.stream(), line))
				body += line;

			logger.information("HANDLER:  %s", request.getURI());
			logger.information("REQUEST:  %s", body);

			FromJsonString(body);
			ValidateData();
			const std::string out = ProcessRequest();

			logger.information("RESPONSE: %s", out);

			response.send() << out;
		}
	}
	catch (ServerException &e)
	{
		Poco::Util::Application::instance().logger().error(e.what());
		response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
		response.send() << e.ToJson();
	}
	catch (Poco::Exception &e)
	{
		Poco::Util::Application::instance().logger().error(DecodeMessage(e.displayText()));
		response.setStatus(Poco::Net::HTTPResponse::HTTP_INTERNAL_SERVER_ERROR);
		response.send() << ResponseCode::GetJson(ResponseCode::Code::INTERNAL_ERROR, "Internal server error");
	}
	catch (std::exception &e)
	{
		Poco::Util::Application::instance().logger().error(e.what());
		response.setStatus(Poco::Net::HTTPResponse::HTTP_INTERNAL_SERVER_ERROR);
		response.send() << ResponseCode::GetJson(ResponseCode::Code::INTERNAL_ERROR, "Internal server error");
	}

	logger.information("\n");
}
