#include "CreateAgriculture.h"
#include "Common/ServerException.h"
#include "Model/Agriculture.h"
#include "Model/User.h"

std::string CreateAgriculture::ProcessRequest()
{
	Agriculture agriculture(name_, humidityMin_, humidityMax_);
	agriculture.CreateSql();
	return agriculture.ToJsonString();
}

void CreateAgriculture::ValidateData() const
{
	User user(token_);
	if (user.GetRole() != User::Role::ADMIN)
		throw ServerException(ServerException::Code::ACCESS_DENIED,
							  "Access denied.");
}

void CreateAgriculture::LoadFromJson(const Poco::JSON::Object::Ptr object)
{
	humidityMax_	= object->getValue<short>("humidity_max");
	humidityMin_	= object->getValue<short>("humidity_min");
	name_			= object->getValue<std::string>("name");
	token_			= object->getValue<std::string>("token");
}
