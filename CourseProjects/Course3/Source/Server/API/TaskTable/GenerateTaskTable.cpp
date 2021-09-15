#include "Common/ServerException.h"
#include "GenerateTaskTable.h"
#include "Model/ResponseCode.h"
#include "Model/TaskTable.h"
#include "Model/User.h"

std::string GenerateTaskTable::ProcessRequest()
{
	User user(token_);
	if (user.GetRole() != User::Role::ADMIN)
		throw ServerException(ServerException::Code::ACCESS_DENIED, "Acces Denied.");

	TaskTable table;
	table.CreateSql();

	return ResponseCode::GetJson(ResponseCode::Code::SUCCESS, "OK");
}

void GenerateTaskTable::LoadFromJson(const Poco::JSON::Object::Ptr object)
{
	token_ = object->getValue<std::string>("token");
}
