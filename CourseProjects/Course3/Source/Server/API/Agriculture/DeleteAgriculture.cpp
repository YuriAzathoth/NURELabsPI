#include "Common/ServerException.h"
#include "Model/Agriculture.h"
#include "Model/User.h"
#include "DeleteAgriculture.h"

std::string DeleteAgriculture::ProcessRequest()
{
	Agriculture agriculture(id_);
	agriculture.DeleteSql();
	return ResponseCode::GetJson(ResponseCode::Code::SUCCESS, "OK");
}

void DeleteAgriculture::ValidateData() const
{
	User user(token_);
	if (user.GetRole() != User::Role::ADMIN)
		throw ServerException(ServerException::Code::ACCESS_DENIED,
							  "Access denied.");
}

void DeleteAgriculture::LoadFromJson(const Poco::JSON::Object::Ptr object)
{
	id_		= object->getValue<int>("id");
	token_	= object->getValue<std::string>("token");
}
