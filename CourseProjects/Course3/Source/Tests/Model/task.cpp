#include <regex>
#include <sstream>
#include <stdexcept>
#include <boost/test/unit_test.hpp>
#include <Poco/DateTime.h>
#include <Poco/Timestamp.h>
#include "Common/ServerException.h"
#include "Model/Field.h"
#include "Model/Task.h"
#include "Model/TaskTable.h"
#include "Model/User.h"

static constexpr char TEST_USER_NAME[] = "user";
static constexpr char TEST_USER_SURNAME[] = "adminson";
static constexpr char TEST_USER_PASSWORD[] = "1234";
static constexpr char TEST_USER_EMAIL[] = "test@mail.com";
static constexpr User::Role TEST_USER_ROLE = User::Role::EMPLOYEE;

static constexpr char TEST_AGRICULTURE_NAME[] = "wheat";
static constexpr short TEST_AGRICULTURE_HMIN = 24;
static constexpr short TEST_AGRICULTURE_HMAX = 32;

static constexpr char TEST_FIELD_CADASTRAL[] = "12:34:1234567:123";
static constexpr short TEST_FIELD_AREA = 100;

static constexpr Task::Status TEST_TASK_STATUS = Task::Status::ACTIVE;
static constexpr Task::Status TEST_TASK_STATUS2 = Task::Status::DONE;

static constexpr char TEST_USER_EMAIL_EMPLOYEES[][16] =
{
	"eone@mail.com",
	"etwo@mail.com",
	"ethree@mail.com",
	"efour@mail.com",
	"efive@mail.com"
};

BOOST_AUTO_TEST_SUITE(TaskTest)

BOOST_AUTO_TEST_CASE(SQL, * boost::unit_test::disabled())
{
	User user(TEST_USER_NAME, TEST_USER_SURNAME, TEST_USER_PASSWORD, TEST_USER_EMAIL, TEST_USER_ROLE);
	user.CreateSql();

	Agriculture agriculture(TEST_AGRICULTURE_NAME, TEST_AGRICULTURE_HMIN, TEST_AGRICULTURE_HMAX);
	agriculture.CreateSql();

	Field field(TEST_FIELD_CADASTRAL, agriculture.GetId(), user.GetId(), TEST_FIELD_AREA);
	field.CreateSql();

	Task create(field.GetId(), user.GetId(), Task::Status::ACTIVE);
	create.CreateSql();

	Task task1(create.GetId());
	BOOST_CHECK_EQUAL(task1.GetFieldId(),		field.GetId());
	BOOST_CHECK_EQUAL(task1.GetEmployeeId(),	user.GetId());
	BOOST_CHECK_EQUAL((int)task1.GetStatus(),	(int)TEST_TASK_STATUS);
	task1.SetStatus(TEST_TASK_STATUS2);
	task1.UpdateSql();

	Task task2(create.GetId());
	BOOST_CHECK_EQUAL(task1.GetFieldId(),		field.GetId());
	BOOST_CHECK_EQUAL(task1.GetEmployeeId(),	user.GetId());
	BOOST_CHECK_EQUAL((int)task1.GetStatus(),	(int)TEST_TASK_STATUS2);

	task1.DeleteSql();

	field.DeleteSql();
	agriculture.DeleteSql();
	user.DeleteSql();
}

BOOST_AUTO_TEST_CASE(Generate, * boost::unit_test::disabled())
{
	User user(TEST_USER_NAME, TEST_USER_SURNAME, TEST_USER_PASSWORD, TEST_USER_EMAIL, User::Role::USER);
	user.CreateSql();

	Agriculture agriculture(TEST_AGRICULTURE_NAME, TEST_AGRICULTURE_HMIN, TEST_AGRICULTURE_HMAX);
	agriculture.CreateSql();

	std::vector<User> employees;
	employees.reserve(5);
	for (int i = 0; i < employees.capacity(); ++i)
	{
		employees.emplace_back(TEST_USER_NAME, TEST_USER_SURNAME, TEST_USER_PASSWORD, TEST_USER_EMAIL_EMPLOYEES[i], User::Role::EMPLOYEE);
		employees.back().CreateSql();
	}

	std::vector<Field> fields;
	fields.reserve(20);
	for (size_t i = 0; i < fields.capacity(); ++i)
	{
		fields.emplace_back("00:00:0000000:0" + std::to_string(i + 20), agriculture.GetId(), user.GetId(), TEST_FIELD_AREA);
		fields.back().CreateSql();
	}

	TaskTable taskTable(-1);
	taskTable.CreateSql();
	BOOST_CHECK_GE(taskTable.GetSize(), fields.size());

	for (Field &field : fields)
		field.DeleteSql();
	for (User &employee : employees)
		employee.DeleteSql();

	agriculture.DeleteSql();
	user.DeleteSql();
}

BOOST_AUTO_TEST_SUITE_END()
