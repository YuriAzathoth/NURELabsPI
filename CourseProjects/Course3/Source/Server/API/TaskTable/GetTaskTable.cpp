#include "Common/ServerException.h"
#include "GetTaskTable.h"
#include "Model/TaskTable.h"
#include "Model/User.h"

std::string GetTaskTable::ProcessRequest()
{
	User user(token_);
	if (user.GetRole() == User::Role::USER)
		throw ServerException(ServerException::Code::ACCESS_DENIED, "Acces Denied.");

	TaskTable table((user.GetRole() == User::Role::ADMIN) ? -1 : user.GetId());
	return table.ToJsonString();
}

void GetTaskTable::LoadFromJson(const Poco::JSON::Object::Ptr object)
{
	token_ = object->getValue<std::string>("token");
}
