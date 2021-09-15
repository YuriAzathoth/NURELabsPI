#include <sstream>
#include <stdexcept>
#include <regex>
#include <boost/test/unit_test.hpp>
#include "Common/ServerException.h"
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

static const std::regex TEST_USER_JSON(R"(^(\{"email":"test@mail.com","name":"user","role":1,"surname":"adminson","token":")([0-9a-z]+)("\})$)");

BOOST_AUTO_TEST_SUITE(UserTest)

BOOST_AUTO_TEST_CASE(Sql)
{
	User create(TEST_USER_NAME, TEST_USER_SURNAME, TEST_USER_PASSWORD, TEST_USER_EMAIL, TEST_USER_ROLE);
	create.CreateSql();

	User byLogin(TEST_USER_EMAIL, TEST_USER_PASSWORD);
	BOOST_CHECK_EQUAL(byLogin.GetName(),		TEST_USER_NAME);
	BOOST_CHECK_EQUAL(byLogin.GetSurname(),		TEST_USER_SURNAME);
	BOOST_CHECK_EQUAL(byLogin.GetEmail(),		TEST_USER_EMAIL);
	BOOST_CHECK_EQUAL((int)byLogin.GetRole(),	(int)TEST_USER_ROLE);

	User byToken(byLogin.GetToken());
	BOOST_CHECK_EQUAL(byToken.GetName(),		TEST_USER_NAME);
	BOOST_CHECK_EQUAL(byToken.GetSurname(),		TEST_USER_SURNAME);
	BOOST_CHECK_EQUAL(byToken.GetEmail(),		TEST_USER_EMAIL);
	BOOST_CHECK_EQUAL((int)byToken.GetRole(),	(int)TEST_USER_ROLE);

	BOOST_CHECK_EQUAL(byLogin.GetToken(),		create.GetToken());
	BOOST_CHECK_EQUAL(byLogin.GetToken(),		create.GetToken());

	byToken.SetName(TEST_USER_NAME2);
	byToken.SetSurname(TEST_USER_SURNAME2);
	byToken.SetPassword(TEST_USER_PASSWORD2);
	byToken.SetEmail(TEST_USER_EMAIL2);
	byToken.UpdateSql();

	User user2(TEST_USER_EMAIL2, TEST_USER_PASSWORD2);
	BOOST_CHECK_EQUAL(user2.GetName(),		TEST_USER_NAME2);
	BOOST_CHECK_EQUAL(user2.GetSurname(),	TEST_USER_SURNAME2);
	BOOST_CHECK_EQUAL(user2.GetEmail(),		TEST_USER_EMAIL2);
	BOOST_CHECK_EQUAL((int)user2.GetRole(),	(int)TEST_USER_ROLE);

	byToken.DeleteSql();

//	BOOST_REQUIRE_THROW(User byLoginFailed1(TEST_USER_EMAIL, TEST_USER_PASSWORD), ServerException);
//	BOOST_REQUIRE_THROW(User byLoginFailed2(TEST_USER_EMAIL2, TEST_USER_PASSWORD2), ServerException);
}

BOOST_AUTO_TEST_CASE(Json)
{
	User toJson(TEST_USER_NAME, TEST_USER_SURNAME, TEST_USER_PASSWORD, TEST_USER_EMAIL, TEST_USER_ROLE);
	BOOST_TEST(std::regex_match(toJson.ToJsonString(), TEST_USER_JSON));

	User fromJson;
	fromJson.FromJsonString(toJson.ToJsonString());
	BOOST_CHECK_EQUAL(fromJson.GetName(),		TEST_USER_NAME);
	BOOST_CHECK_EQUAL(fromJson.GetSurname(),	TEST_USER_SURNAME);
	BOOST_CHECK_EQUAL(fromJson.GetEmail(),		TEST_USER_EMAIL);
	BOOST_CHECK_EQUAL((int)fromJson.GetRole(),	(int)TEST_USER_ROLE);
	BOOST_CHECK_EQUAL(static_cast<int>(fromJson.GetRole()), static_cast<int>(TEST_USER_ROLE));
}

BOOST_AUTO_TEST_SUITE_END()
