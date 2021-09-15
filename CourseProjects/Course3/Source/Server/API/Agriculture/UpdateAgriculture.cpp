#include "UpdateAgriculture.h"
#include "Common/ServerException.h"
#include "Model/Agriculture.h"
#include "Model/ResponseCode.h"
#include "Model/User.h"

std::string UpdateAgriculture::ProcessRequest()
{
	Agriculture agriculture(id_, name_, humidityMin_, humidityMax_);
	agriculture.UpdateSql();
	return ResponseCode::GetJson(ResponseCode::Code::SUCCESS, "OK");
}

void UpdateAgriculture::ValidateData() const
{
	User user(token_);
	if (user.GetRole() != User::Role::ADMIN)
		throw ServerException(ServerException::Code::ACCESS_DENIED,
							  "Access denied.");
}

void UpdateAgriculture::LoadFromJson(const Poco::JSON::Object::Ptr object)
{
	id_				= object->get("id").convert<int>();
	humidityMax_	= object->get("humidity_max").convert<short>();
	humidityMin_	= object->get("humidity_min").convert<short>();
	name_			= object->get("name").convert<std::string>();
	token_			= object->get("token").convert<std::string>();
}

