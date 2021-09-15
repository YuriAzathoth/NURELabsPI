#include "Common/ServerException.h"
#include "Model/Field.h"
#include "Model/ResponseCode.h"
#include "Model/User.h"
#include "DeleteField.h"

std::string DeleteField::ProcessRequest()
{
	Field field(id_);
	field.DeleteSql();
	return ResponseCode::GetJson(ResponseCode::Code::SUCCESS, "OK");
}

void DeleteField::ValidateData() const
{
	User user(token_);
	Field field(id_);
	if (user.GetRole() != User::Role::ADMIN &&
		user.GetId() != field.GetUserId())
		throw ServerException(ServerException::Code::ACCESS_DENIED,
							  "Access denied.");
}

void DeleteField::LoadFromJson(const Poco::JSON::Object::Ptr object)
{
	id_		= object->getValue<int>("id");
	token_	= object->getValue<std::string>("token");
}
