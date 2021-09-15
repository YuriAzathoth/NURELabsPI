#include <cstdint>
#include <sstream>
#include <stdexcept>
#include <Poco/Net/Context.h>
#include <Poco/Net/HTTPSClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/NetException.h>
#include <Poco/URI.h>
#include <Poco/Util/Application.h>
#include <Poco/Util/LayeredConfiguration.h>
#include "common.h"

std::string TestApi(const std::string &handler, const Poco::JSON::Object::Ptr data)
{
	std::stringstream reqstream;
	if (data)
		data->stringify(reqstream);
	const std::string request_data = data ? reqstream.str() : "";

	try
	{
		const Poco::URI uri("localhost");
		const uint16_t port = static_cast<uint16_t>(Poco::Util::Application::instance().config().getUInt("Https.port"));
		Poco::Net::HTTPSClientSession session(uri.getHost(), port);

		Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_POST, "/api" + handler);
		request.setKeepAlive(true);
		request.setContentType("application/json");
		request.setContentLength(request_data.size());
		session.sendRequest(request) << request_data;

		std::string received;
		Poco::Net::HTTPResponse response;
		std::getline(session.receiveResponse(response), received);
		return received;
	}
	catch (Poco::Net::NetException &e)
	{
		throw std::runtime_error(e.message());
	}
}
