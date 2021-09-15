#ifndef SIGNUP_H
#define SIGNUP_H

#include "API/RequestHandler.h"

class SignUp : public RequestHandler
{
private:
	std::string ProcessRequest() override final;
	void ValidateData() const override final;
	void LoadFromJson(const Poco::JSON::Object::Ptr object) override final;

	std::string name_;
	std::string surname_;
	std::string password_;
	std::string email_;
	int role_;
};

#endif // SIGNUP_H
