#include "PCH.h"
#include "ContentApi.h"

void ContentApi::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
	std::string file_name = Poco::Util::Application::instance().config().getString("Content.dir", "../share/Content") + request.getURI();
	std::ifstream content_file(file_name, std::ios::binary);
	if (content_file.is_open())
	{
		std::string content((std::istreambuf_iterator<char>(content_file)), std::istreambuf_iterator<char>());
		response.send() << content;
	}
	else
	{
		Poco::Util::Application::instance().logger().error("Failed to handle address %s", Poco::Any(file_name));
		response.redirect("/");
	}
}
