#include "LogIn.h"
#include "Model/User.h"

std::string LogIn::ProcessRequest()
{
	User user(email_, password_);
	return user.ToJsonString();
}

void LogIn::LoadFromJson(const Poco::JSON::Object::Ptr object)
{
	email_		= object->getValue<std::string>("email");
	password_	= object->getValue<std::string>("password");
}
