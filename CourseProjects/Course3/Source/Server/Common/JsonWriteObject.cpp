#include <sstream>
#include <Poco/Dynamic/Var.h>
#include <Poco/JSON/Parser.h>
#include <Poco/JSON/Stringifier.h>
#include <Poco/Logger.h>
#include <Poco/Util/Application.h>
#include "JsonWriteObject.h"

std::string JsonWriteObject::ToJsonString() const
{
	try
	{
		std::stringstream json;
		ToJsonObject()->stringify(json);
		return json.str();
	}
	catch (Poco::JSON::JSONException &e)
	{
		Poco::Util::Application::instance().logger().error(e.displayText());
		throw e;
	}
}

Poco::JSON::Object::Ptr JsonWriteObject::ToJsonObject() const
{
	Poco::JSON::Object::Ptr json = new Poco::JSON::Object;
	SaveToJson(json);
	return json;
}
