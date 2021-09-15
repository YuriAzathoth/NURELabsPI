#include <sstream>
#include <Poco/Dynamic/Var.h>
#include <Poco/JSON/Parser.h>
#include <Poco/JSON/Stringifier.h>
#include <Poco/Logger.h>
#include <Poco/Util/Application.h>
#include "JsonReadObject.h"

void JsonReadObject::FromJsonString(std::string json)
{
	if (json.empty())
		return;

	try
	{
		Poco::JSON::Parser parser;
		parser.parse(json);
		FromJsonObject(parser.result().extract<Poco::JSON::Object::Ptr>());
	}
	catch (Poco::JSON::JSONException &e)
	{
		Poco::Util::Application::instance().logger().error(e.displayText());
		throw e;
	}
}


void JsonReadObject::FromJsonObject(Poco::JSON::Object::Ptr json)
{
	LoadFromJson(json);
}
