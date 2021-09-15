#include <cstdlib>
#include <iostream>
#include <Poco/Data/ODBC/Connector.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPServerParams.h>
#include <Poco/Net/SecureServerSocket.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Timer.h>
#include <Poco/Util/ServerApplication.h>
#include "API/RequestFactory.h"

class Server : public Poco::Util::ServerApplication
{
	void initialize(Poco::Util::Application &self) override final;
	int main(const std::vector<std::string>&) override final;
};

void Server::initialize(Poco::Util::Application &self)
{
	setlocale(LC_ALL, "");

	loadConfiguration("../share/Config/settings.properties");
	Poco::Data::ODBC::Connector::registerConnector();

	Poco::Util::ServerApplication::initialize(self);
}

int Server::main(const std::vector<std::string>&)
{
	logger().setLevel(config().getString("Logger.level"));

	Poco::Net::ServerSocket http_socket(static_cast<Poco::UInt16>(config().getUInt("Http.port")));
	Poco::Net::SecureServerSocket https_socket(static_cast<Poco::UInt16>(config().getUInt("Https.port")));

	Poco::Net::HTTPServer http_server(new RequestFactory, http_socket, new Poco::Net::HTTPServerParams);
	Poco::Net::HTTPServer https_server(new RequestFactory, https_socket, new Poco::Net::HTTPServerParams);

	http_server.start();
	https_server.start();

	waitForTerminationRequest();

	https_server.stop();
	http_server.stop();

	return Application::EXIT_OK;
}

POCO_SERVER_MAIN(Server)
