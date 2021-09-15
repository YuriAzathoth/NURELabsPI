#include "Core/MobRequestFactory.h"
#include "Core/WebRequestFactory.h"

class ServerCore : public Poco::Util::ServerApplication
{
public:
	using Poco::Util::ServerApplication::ServerApplication;
private:
	void initialize(Poco::Util::Application &self) override final;
	int main(const std::vector<std::string> &args) override final;
};

void ServerCore::initialize(Poco::Util::Application &self)
{
	setlocale(LC_ALL, "");
	loadConfiguration("../share/Config/settings.properties");
	Poco::Util::ServerApplication::initialize(self);
}

int ServerCore::main(const std::vector<std::string> &args)
{
	Poco::Net::SecureServerSocket	socket_main	(config().getUInt("WebServer.port"));
	Poco::Net::ServerSocket			socket_aux	(config().getUInt("MobServer.port"));
	Poco::Net::HTTPServer			server_main	(new WebRequestFactory, socket_main, new Poco::Net::HTTPServerParams);
	Poco::Net::HTTPServer			server_aux	(new MobRequestFactory, socket_aux, new Poco::Net::HTTPServerParams);

	server_main.start();
	server_aux.start();
	waitForTerminationRequest();
	server_aux.stop();
	server_main.stop();

	return Poco::Util::Application::EXIT_OK;
}

POCO_SERVER_MAIN(ServerCore);
