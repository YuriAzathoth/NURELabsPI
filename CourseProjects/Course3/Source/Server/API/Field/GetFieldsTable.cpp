#include "GetFieldsTable.h"
#include "Model/FieldTable.h"
#include "Model/User.h"

std::string GetFieldsTable::ProcessRequest()
{
	User user(token_);
	const int userId = (user.GetRole() == User::Role::ADMIN ||
						user.GetRole() == User::Role::EMPLOYEE) ?
					   -1 : static_cast<int>(user.GetId());
	FieldTable table(userId);
	return table.ToJsonString();
}

void GetFieldsTable::LoadFromJson(const Poco::JSON::Object::Ptr object)
{
	token_ = object->getValue<std::string>("token");
}
