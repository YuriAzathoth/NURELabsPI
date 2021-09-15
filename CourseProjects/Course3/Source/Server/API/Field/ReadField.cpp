#include "Common/ServerException.h"
#include "Model/Field.h"
#include "Model/User.h"
#include "ReadField.h"

std::string ReadField::ProcessRequest()
{
	Field field(id_);
	return field.ToJsonString();
}

void ReadField::ValidateData() const
{
	User user(token_);
	Field field(id_);
	if (user.GetRole() != User::Role::ADMIN &&
		user.GetRole() != User::Role::EMPLOYEE &&
		user.GetId() != field.GetUserId())
		throw ServerException(ServerException::Code::ACCESS_DENIED,
							  "Access denied.");
}

void ReadField::LoadFromJson(const Poco::JSON::Object::Ptr object)
{
	id_		= object->getValue<int>("id");
	token_	= object->getValue<std::string>("token");
}
