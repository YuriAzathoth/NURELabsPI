#include <regex>
#include "Common/ServerException.h"
#include "CreateField.h"
#include "Model/Field.h"
#include "Model/User.h"

std::string CreateField::ProcessRequest()
{
	User user(token_);
	Field field(cadastral_, agriculture_, user.GetId(), area_);
	field.CreateSql();
	return field.ToJsonString();
}

void CreateField::ValidateData() const
{
	static const std::regex CADASTRAL_REGEX("^([0-9]{2}:[0-9]{2}:[0-9]{7}:[0-9]{3})$$");

	if (!std::regex_match(cadastral_, CADASTRAL_REGEX))
		throw ServerException(ServerException::Code::INVALID_DATA,
							  "Invalid cadastral number.");
}

void CreateField::LoadFromJson(const Poco::JSON::Object::Ptr object)
{
	agriculture_	= object->getValue<int>("agriculture");
	area_			= object->getValue<short>("area");
	cadastral_		= object->getValue<std::string>("cadastral");
	token_			= object->getValue<std::string>("token");
}
