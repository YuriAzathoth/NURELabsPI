#include <cstdint>
#include <stdexcept>
#include <Poco/Net/AcceptCertificateHandler.h>
#include <Poco/Net/Context.h>
#include <Poco/Net/HTTPSClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/NetException.h>
#include <Poco/Net/SSLManager.h>
#include <Poco/URI.h>
#include <Poco/Util/Application.h>
#include <Poco/Util/LayeredConfiguration.h>
#include "common.h"

std::string ServerRequest(const std::string &handler, const std::string &request_data)
{
	try
	{
		Poco::Net::Context::Ptr context = new Poco::Net::Context(Poco::Net::Context::CLIENT_USE, "");
		context->enableExtendedCertificateVerification(false);
		Poco::Net::SSLManager::InvalidCertificateHandlerPtr invalid_handler = new Poco::Net::AcceptCertificateHandler(false);
		Poco::Net::SSLManager::instance().initializeClient(0, invalid_handler, context);

		const Poco::URI uri("localhost");
		const uint16_t port = 8000;

		Poco::Net::HTTPSClientSession session(uri.getHost(), port);

		Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_POST, std::string("/api") + handler);
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
