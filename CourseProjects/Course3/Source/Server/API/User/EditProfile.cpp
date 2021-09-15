#include <regex>
#include "Common/ServerException.h"
#include "EditProfile.h"
#include "Model/ResponseCode.h"
#include "Model/User.h"

std::string EditProfile::ProcessRequest()
{
	User user(oldEmail_, oldPassword_);

	if (!surname_.empty())
		user.SetSurname(surname_);
	if (!name_.empty())
		user.SetName(name_);
	if (!password_.empty())
		user.SetPassword(password_);
	if (!email_.empty())
		user.SetEmail(email_);
	user.UpdateSql();

	return ResponseCode::GetJson(ResponseCode::Code::SUCCESS, "OK");
}

void EditProfile::ValidateData() const
{
	static const std::regex NAME_REGEX("^([A-Za-zА-Яа-я]+)$");
	static const std::regex PASSWORD_REGEX("^([0-9A-Za-z]+)$");
	static const std::regex EMAIL_REGEX("^([a-z.]+)@([a-z]+).([a-z]+)$");

	if (!name_.empty() && !std::regex_match(name_, NAME_REGEX))
		throw ServerException(ServerException::Code::INVALID_DATA,
							  "Invalid name.");

	if (!surname_.empty() && !std::regex_match(surname_, NAME_REGEX))
		throw ServerException(ServerException::Code::INVALID_DATA,
							  "Invalid surname.");

	if (!password_.empty() && !std::regex_match(password_, PASSWORD_REGEX))
		throw ServerException(ServerException::Code::INVALID_DATA,
							  "Invalid password.");

	if (!email_.empty() && !std::regex_match(email_, EMAIL_REGEX))
		throw ServerException(ServerException::Code::INVALID_DATA,
							  "Invalid email.");
}

void EditProfile::LoadFromJson(const Poco::JSON::Object::Ptr object)
{
	const Poco::JSON::Object::Ptr jsonLogin = object->getObject("login");
	oldEmail_		= jsonLogin->getValue<std::string>("email");
	oldPassword_	= jsonLogin->getValue<std::string>("password");

	const Poco::JSON::Object::Ptr jsonEdit = object->getObject("edit");
	if (jsonEdit->has("email"))
		email_		= jsonEdit->getValue<std::string>("email");
	if (jsonEdit->has("name"))
		name_		= jsonEdit->getValue<std::string>("name");
	if (jsonEdit->has("password"))
		password_	= jsonEdit->getValue<std::string>("password");
	if (jsonEdit->has("surname"))
		surname_	= jsonEdit->getValue<std::string>("surname");
}
