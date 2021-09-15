#include "ResponseCode.h"

ResponseCode::ResponseCode(Code code, const std::string &message) :
	code_(static_cast<int>(code)),
	message_(message)
{
}

void ResponseCode::LoadFromJson(const Poco::JSON::Object::Ptr object)
{
	message_	= object->getValue<std::string>("message");
	code_		= object->getValue<int>("code");
}

void ResponseCode::SaveToJson(Poco::JSON::Object::Ptr object) const
{
	object->set("message",	message_);
	object->set("code",		code_);
}

std::string ResponseCode::GetJson(Code code, const std::string &message)
{
	return ResponseCode(code, message).ToJsonString();
}
