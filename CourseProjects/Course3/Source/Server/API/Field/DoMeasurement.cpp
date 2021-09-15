#include "Common/ServerException.h"
#include "DoMeasurement.h"
#include "Model/Field.h"
#include "Model/IrrigationRecord.h"
#include "Model/TaskTable.h"
#include "Model/User.h"

static constexpr float HUMIDITY_MIN = 0.0f;
static constexpr float HUMIDITY_MAX = 100.0f;

std::string DoMeasurement::ProcessRequest()
{
	const User user(token_);
	Field field(id_);

	Task task(field.GetId(), user.GetId());
	if (task.GetId() > 0)
	{
		task.SetStatus(Task::Status::DONE);
		task.UpdateSql();
	}

	return field.DoMeasurement(humidity_).ToJsonString();
}

void DoMeasurement::ValidateData() const
{
	User user(token_);
	Field field(id_);
	if (user.GetRole() != User::Role::ADMIN &&
		user.GetRole() != User::Role::EMPLOYEE &&
		user.GetId() != field.GetUserId())
		throw ServerException(ServerException::Code::ACCESS_DENIED,
							  "Access denied.");

	if (humidity_ < HUMIDITY_MIN || humidity_ > HUMIDITY_MAX)
		throw ServerException(ServerException::Code::INVALID_DATA,
							  "Humidity is out of range.");
}

void DoMeasurement::LoadFromJson(const Poco::JSON::Object::Ptr object)
{
	humidity_	= object->getValue<short>("humidity");
	id_			= object->getValue<int>("id");
	token_		= object->getValue<std::string>("token");
}
