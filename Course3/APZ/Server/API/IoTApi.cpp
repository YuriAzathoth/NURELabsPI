#include "PCH.h"
#include "IoTApi.h"
#include "Utility.h"

using namespace Poco::Data::Keywords;

void IoTApi::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
	std::string address = request.clientAddress().toString();
	address = address.substr(0, address.find_first_of(":"));

	const Poco::Net::HTMLForm form(request, request.stream());
    int temperature	= std::stoi(form["t"]);
    int humidity	= std::stoi(form["h"]);

    GetContext()->GetDb().NewSession() <<
		R"(UPDATE "warehouses" SET "warehouse_temperature" = ?, "warehouse_humidity" = ? WHERE "warehouse_iot_ip" = ?)",
		use(temperature), use(humidity), use(address), now;
}
