#include <regex>
#include "Common/ServerException.h"
#include "Model/ResponseCode.h"
#include "Model/User.h"
#include "SignUp.h"

std::string SignUp::ProcessRequest()
{
	User user(name_, surname_, password_, email_, static_cast<User::Role>(role_));
	user.CreateSql();
	return ResponseCode::GetJson(ResponseCode::Code::SUCCESS, "OK");
}

void SignUp::ValidateData() const
{
	static const std::regex NAME_REGEX("^([A-Za-zА-Яа-я]+)$");
	static const std::regex PASSWORD_REGEX("^([0-9A-Za-z]+)$");
	static const std::regex EMAIL_REGEX("^([a-z.]+)@([a-z]+).([a-z]+)$");

	if (!(static_cast<User::Role>(role_) == User::Role::USER) ||
		(static_cast<User::Role>(role_) == User::Role::EMPLOYEE))
		throw ServerException(ServerException::Code::INVALID_DATA,
							  "Invalid role.");

	if (!std::regex_match(name_, NAME_REGEX))
		throw ServerException(ServerException::Code::INVALID_DATA,
							  "Invalid name.");

	if (!std::regex_match(surname_, NAME_REGEX))
		throw ServerException(ServerException::Code::INVALID_DATA,
							  "Invalid surname.");

	if (!std::regex_match(password_, PASSWORD_REGEX))
		throw ServerException(ServerException::Code::INVALID_DATA,
							  "Invalid password.");

	if (!std::regex_match(email_, EMAIL_REGEX))
		throw ServerException(ServerException::Code::INVALID_DATA,
							  "Invalid email.");
}

void SignUp::LoadFromJson(const Poco::JSON::Object::Ptr object)
{
	name_		= object->getValue<std::string>("name");
	surname_	= object->getValue<std::string>("surname");
	password_	= object->getValue<std::string>("password");
	email_		= object->getValue<std::string>("email");
	role_		= object->getValue<int>("role");
}
