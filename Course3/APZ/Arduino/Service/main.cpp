#include <Poco/Net/HTMLForm.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include "w32.h"

constexpr char SERVER_HOST[]	= "localhost";
constexpr char SERVER_HANDLER[]	= "/iot";
constexpr int SERVER_PORT		= 9981;
constexpr int BUFFER_SIZE		= 64;

int main(int argc, char** argv)
{
	char buffer[BUFFER_SIZE];
	char port_iot[5];
	if (argc == 1)
		strcpy(port_iot, "com3");
	else if (argc > 1)
		strcpy(port_iot, argv[1]);

	Serial com(port_iot);
	Poco::Net::HTTPClientSession client(SERVER_HOST, SERVER_PORT);

	std::string data;
	std::string temp;
	int t;
	int h;
	int delim;

	while (true)
	{
		try
		{
			memset((void*)buffer, 0, BUFFER_SIZE);
			com.ReadData(buffer, BUFFER_SIZE - 1);
			size_t len = strlen(buffer);
			if (!len)
				throw 0;
//			printf("%s\n", buffer);

			data = buffer;
			data.erase(data.begin());
			data.erase(data.end() - 1);
			delim = data.find_first_of(";");

			temp = data.substr(0, delim);
			t = std::stoi(temp);
			temp = data.substr(delim + 1);
			h = std::stoi(temp);

			Poco::Net::HTTPRequest	request(Poco::Net::HTTPRequest::HTTP_GET, SERVER_HANDLER);
			Poco::Net::HTMLForm		form;
			form.add("t", std::to_string(t));
			form.add("h", std::to_string(h));
			form.prepareSubmit(request);
			client.sendRequest(request);
		}
		catch (...)
		{
			continue;
		}
	}

	return 0;
}
