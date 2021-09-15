#include <boost/test/unit_test.hpp>
#include <Poco/JSON/Object.h>
#include "common.h"
#include "Model/ResponseCode.h"
#include "Model/Agriculture.h"
#include "Model/AgricultureTable.h"
#include "Model/User.h"

#define TEST_AGRICULTURE_SINGLE R"(^(\{"frequency":2,"humidity_max":32,"humidity_min":24,"id":)([0-9]+)(,"name":"wheat"\})$)"
#define TEST_AGRICULTURE_SINGLE2 R"(^(\{"frequency":4,"humidity_max":80,"humidity_min":60,"id":)([0-9]+)(,"name":"reese"\})$)"
#define TEST_AGRICULTURE_TABLE R"(^(\{"table":\[)(.*)(\]\})$)"

static constexpr char TEST_USER_NAME[] = "user";
static constexpr char TEST_USER_SURNAME[] = "adminson";
static constexpr char TEST_USER_PASSWORD[] = "12341234";
static constexpr char TEST_USER_EMAIL[] = "test@mail.com";
static constexpr User::Role TEST_USER_ROLE = User::Role::ADMIN;

static constexpr char TEST_AGRICULTURE_NAME[] = "wheat";
static constexpr short TEST_AGRICULTURE_HMIN = 24;
static constexpr short TEST_AGRICULTURE_HMAX = 32;

static constexpr char TEST_AGRICULTURE_NAME2[] = "reese";
static constexpr short TEST_AGRICULTURE_HMIN2 = 60;
static constexpr short TEST_AGRICULTURE_HMAX2 = 80;

BOOST_AUTO_TEST_CASE(AgricultureAPI)
{
	Poco::JSON::Object::Ptr jsonRequest = new Poco::JSON::Object;
	Poco::JSON::Object::Ptr jsonResponse;
	ResponseCode responseCode;
	std::string response;

	User user(TEST_USER_NAME, TEST_USER_SURNAME, TEST_USER_PASSWORD, TEST_USER_EMAIL, TEST_USER_ROLE);
	user.CreateSql();

	Agriculture create;
	jsonRequest->set("name",			TEST_AGRICULTURE_NAME);
	jsonRequest->set("humidity_min",	TEST_AGRICULTURE_HMIN);
	jsonRequest->set("humidity_max",	TEST_AGRICULTURE_HMAX);
	jsonRequest->set("token",			user.GetToken());
	response = TestApi("/agriculture/create", jsonRequest);
	create.FromJsonString(response);
	BOOST_CHECK_EQUAL(create.GetName(),			TEST_AGRICULTURE_NAME);
	BOOST_CHECK_EQUAL(create.GetHumidityMin(),	TEST_AGRICULTURE_HMIN);
	BOOST_CHECK_EQUAL(create.GetHumidityMax(),	TEST_AGRICULTURE_HMAX);

	Agriculture read1;
	jsonRequest->clear();
	jsonRequest->set("id", create.GetId());
	response = TestApi("/agriculture/read", jsonRequest);
	read1.FromJsonString(response);
	BOOST_CHECK_EQUAL(read1.GetName(),			TEST_AGRICULTURE_NAME);
	BOOST_CHECK_EQUAL(read1.GetHumidityMin(),	TEST_AGRICULTURE_HMIN);
	BOOST_CHECK_EQUAL(read1.GetHumidityMax(),	TEST_AGRICULTURE_HMAX);

	jsonRequest->clear();
	jsonRequest->set("id",				read1.GetId());
	jsonRequest->set("name",			TEST_AGRICULTURE_NAME2);
	jsonRequest->set("humidity_min",	TEST_AGRICULTURE_HMIN2);
	jsonRequest->set("humidity_max",	TEST_AGRICULTURE_HMAX2);
	jsonRequest->set("token",			user.GetToken());
	response = TestApi("/agriculture/update", jsonRequest);
	responseCode.FromJsonString(response);
	BOOST_CHECK_EQUAL((int)responseCode.GetCode(),	(int)ResponseCode::Code::SUCCESS);
	BOOST_CHECK_EQUAL(responseCode.GetMessage(),	"OK");

	Agriculture read2;
	jsonRequest->clear();
	jsonRequest->set("id", create.GetId());
	response = TestApi("/agriculture/read", jsonRequest);
	read2.FromJsonString(response);
	BOOST_CHECK_EQUAL(read2.GetName(),			TEST_AGRICULTURE_NAME2);
	BOOST_CHECK_EQUAL(read2.GetHumidityMin(),	TEST_AGRICULTURE_HMIN2);
	BOOST_CHECK_EQUAL(read2.GetHumidityMax(),	TEST_AGRICULTURE_HMAX2);

	AgricultureTable table;
	response = TestApi("/agriculture/table", nullptr);
	table.FromJsonString(response);
	BOOST_CHECK_GE(table.GetSize(), 1);

	jsonRequest->clear();
	jsonRequest->set("id",		read1.GetId());
	jsonRequest->set("token",	user.GetToken());
	response = TestApi("/agriculture/delete", jsonRequest);
	responseCode.FromJsonString(response);
	BOOST_CHECK_EQUAL((int)responseCode.GetCode(),	(int)ResponseCode::Code::SUCCESS);
	BOOST_CHECK_EQUAL(responseCode.GetMessage(),	"OK");

	user.DeleteSql();
}
