#include <algorithm>
#include <boost/test/unit_test.hpp>
#include <Poco/JSON/Object.h>
#include "common.h"
#include "Model/Agriculture.h"
#include "Model/Field.h"
#include "Model/IrrigationRecord.h"
#include "Model/ResponseCode.h"
#include "Model/TaskTable.h"
#include "Model/User.h"

static constexpr char TEST_USER_NAME[] = "user";
static constexpr char TEST_USER_SURNAME[] = "adminson";
static constexpr char TEST_USER_PASSWORD[] = "12341234";
static constexpr char TEST_USER_EMAIL[] = "test@mail.com";
static constexpr User::Role TEST_USER_ROLE = User::Role::ADMIN;
static constexpr User::Role TEST_USER_ROLE2 = User::Role::EMPLOYEE;

static constexpr char TEST_AGRICULTURE_NAME[] = "wheat";
static constexpr short TEST_AGRICULTURE_HMIN = 24;
static constexpr short TEST_AGRICULTURE_HMAX = 32;

static constexpr char TEST_FIELD_CADASTRAL[] = "12:34:1234567:123";
static constexpr short TEST_FIELD_AREA = 100;
static constexpr short TEST_FIELD_AREA2 = 200;

static constexpr short TEST_IRRIGATION_HUMIDITIES[] = { 26, 28, 22, 36 };
static constexpr IrrigationRecord::Decission TEST_IRRIGATION_DECISSIONS[] =
{
	IrrigationRecord::Decission::NONE,
	IrrigationRecord::Decission::NONE,
	IrrigationRecord::Decission::IRRIGATE,
	IrrigationRecord::Decission::DRAIN
};

static constexpr char TEST_USER_EMAIL_EMPLOYEES[][16] =
{
	"eone@mail.com",
	"etwo@mail.com",
	"ethree@mail.com",
	"efour@mail.com",
	"efive@mail.com"
};

BOOST_AUTO_TEST_CASE(TaskAPI, * boost::unit_test::disabled())
{
	Poco::JSON::Object::Ptr jsonRequest = new Poco::JSON::Object;
	Poco::JSON::Object::Ptr jsonResponse;
	ResponseCode responseCode;
	std::string response;

	User user(TEST_USER_NAME, TEST_USER_SURNAME, TEST_USER_PASSWORD, TEST_USER_EMAIL, TEST_USER_ROLE);
	user.CreateSql();

	Agriculture agriculture(TEST_AGRICULTURE_NAME, TEST_AGRICULTURE_HMIN, TEST_AGRICULTURE_HMAX);
	agriculture.CreateSql();

	std::vector<User> employees;
	employees.reserve(5);
	for (int i = 0; i < employees.capacity(); ++i)
	{
		employees.emplace_back(TEST_USER_NAME, TEST_USER_SURNAME, TEST_USER_PASSWORD, TEST_USER_EMAIL_EMPLOYEES[i], TEST_USER_ROLE2);
		employees.back().CreateSql();
	}

	std::vector<Field> fields;
	fields.reserve(20);
	for (size_t i = 0; i < fields.capacity(); ++i)
	{
		fields.emplace_back("00:00:0000000:0" + std::to_string(i + 20), agriculture.GetId(), user.GetId(), TEST_FIELD_AREA);
		fields.back().CreateSql();
	}

	jsonRequest->clear();
	jsonRequest->set("token", user.GetToken());
	BOOST_CHECK_EQUAL(TestApi("/task/create", jsonRequest), ResponseCode::GetJson(ResponseCode::Code::SUCCESS, "OK"));

	TaskTable table1;
	table1.FromJsonString(TestApi("/task/get", jsonRequest));
	BOOST_CHECK_GE(table1.GetSize(), fields.size());
	for (const Task &task : table1.GetTable())
		BOOST_CHECK_EQUAL((int)task.GetStatus(), (int)Task::Status::ACTIVE);

	for (Field &field : fields)
		field.DeleteSql();
	for (User &employee : employees)
		employee.DeleteSql();

	agriculture.DeleteSql();
	user.DeleteSql();
}
