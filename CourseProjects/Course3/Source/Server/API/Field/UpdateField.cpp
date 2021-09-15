#include "Common/ServerException.h"
#include "Model/Field.h"
#include "Model/ResponseCode.h"
#include "Model/User.h"
#include "UpdateField.h"

std::string UpdateField::ProcessRequest()
{
	Field field(id_);
	field.SetAgriculture(agriculture_);
	field.SetArea(area_);
	field.UpdateSql();
	return ResponseCode::GetJson(ResponseCode::Code::SUCCESS, "OK");
}

void UpdateField::ValidateData() const
{
	User user(token_);
	Field field(id_);
	if (user.GetRole() != User::Role::ADMIN &&
		user.GetId() != field.GetUserId())
		throw ServerException(ServerException::Code::ACCESS_DENIED,
							  "Access denied.");
}

void UpdateField::LoadFromJson(const Poco::JSON::Object::Ptr object)
{
	agriculture_	= object->getValue<int>("agriculture");
	area_			= object->getValue<short>("area");
	id_				= object->getValue<int>("id");
	token_			= object->getValue<std::string>("token");
}
