#include <boost/test/unit_test.hpp>
#include <Poco/JSON/Object.h>
#include "common.h"
#include "Model/ResponseCode.h"
#include "Model/User.h"

static constexpr char TEST_USER_NAME[] = "user";
static constexpr char TEST_USER_SURNAME[] = "adminson";
static constexpr char TEST_USER_PASSWORD[] = "12341234";
static constexpr char TEST_USER_EMAIL[] = "test@mail.com";
static constexpr User::Role TEST_USER_ROLE = User::Role::USER;

static constexpr char TEST_USER_NAME2[] = "test";
static constexpr char TEST_USER_SURNAME2[] = "noob";
static constexpr char TEST_USER_PASSWORD2[] = "24682468";
static constexpr char TEST_USER_EMAIL2[] = "test@test.ua";

BOOST_AUTO_TEST_CASE(UserAPI)
{
	Poco::JSON::Object::Ptr jsonRequest = new Poco::JSON::Object;
	Poco::JSON::Object::Ptr jsonResponse;
	ResponseCode responseCode;
	std::string response;

	jsonRequest->set("name",	TEST_USER_NAME);
	jsonRequest->set("surname",	TEST_USER_SURNAME);
	jsonRequest->set("password",TEST_USER_PASSWORD);
	jsonRequest->set("email",	TEST_USER_EMAIL);
	jsonRequest->set("role",	(int)TEST_USER_ROLE);

	response = TestApi("/user/signup", jsonRequest);
	responseCode.FromJsonString(response);
	BOOST_CHECK_EQUAL((int)responseCode.GetCode(),	(int)ResponseCode::Code::SUCCESS);
	BOOST_CHECK_EQUAL(responseCode.GetMessage(),	"OK");

	jsonRequest->clear();
	jsonRequest->set("email",	TEST_USER_EMAIL);
	jsonRequest->set("password",TEST_USER_PASSWORD);
	response = TestApi("/user/login", jsonRequest);

	User login1;
	login1.FromJsonString(response);
	BOOST_CHECK_EQUAL(login1.GetSurname(),	TEST_USER_SURNAME);
	BOOST_CHECK_EQUAL(login1.GetName(),		TEST_USER_NAME);
	BOOST_CHECK_EQUAL(login1.GetEmail(),	TEST_USER_EMAIL);
	BOOST_CHECK_EQUAL((int)login1.GetRole(),(int)TEST_USER_ROLE);

	jsonRequest->clear();

	Poco::JSON::Object::Ptr jsonLogin = new Poco::JSON::Object;
	jsonLogin->set("email",		TEST_USER_EMAIL);
	jsonLogin->set("password",	TEST_USER_PASSWORD);
	jsonRequest->set("login",	jsonLogin);

	Poco::JSON::Object::Ptr jsonData = new Poco::JSON::Object;
	jsonData->set("name",		TEST_USER_NAME2);
	jsonData->set("surname",	TEST_USER_SURNAME2);
	jsonData->set("password",	TEST_USER_PASSWORD2);
	jsonData->set("email",		TEST_USER_EMAIL2);
	jsonRequest->set("edit",	jsonData);

	response = TestApi("/user/edit", jsonRequest);
	responseCode.FromJsonString(response);
	BOOST_CHECK_EQUAL((int)responseCode.GetCode(),	(int)ResponseCode::Code::SUCCESS);
	BOOST_CHECK_EQUAL(responseCode.GetMessage(),	"OK");

	jsonRequest->clear();
	jsonRequest->set("email",		TEST_USER_EMAIL2);
	jsonRequest->set("password",	TEST_USER_PASSWORD2);
	response = TestApi("/user/login", jsonRequest);

	User login2;
	login2.FromJsonString(response);
	BOOST_CHECK_EQUAL(login2.GetId(),		login1.GetId());
	BOOST_CHECK_EQUAL(login2.GetSurname(),	TEST_USER_SURNAME2);
	BOOST_CHECK_EQUAL(login2.GetName(),		TEST_USER_NAME2);
	BOOST_CHECK_EQUAL(login2.GetEmail(),	TEST_USER_EMAIL2);
	BOOST_CHECK_EQUAL((int)login2.GetRole(),(int)TEST_USER_ROLE);

	User del(TEST_USER_EMAIL2, TEST_USER_PASSWORD2);
	del.DeleteSql();
}
