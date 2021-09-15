#ifndef LOGIN_H
#define LOGIN_H

#include "API/RequestHandler.h"

class LogIn : public RequestHandler
{
private:
	std::string ProcessRequest() override final;
	void LoadFromJson(const Poco::JSON::Object::Ptr object) override final;

	std::string email_;
	std::string password_;
};

#endif // LOGIN_H
