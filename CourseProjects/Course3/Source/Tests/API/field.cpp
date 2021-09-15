#include <boost/test/unit_test.hpp>
#include <Poco/JSON/Object.h>
#include "common.h"
#include "Model/Agriculture.h"
#include "Model/Field.h"
#include "Model/IrrigationRecord.h"
#include "Model/ResponseCode.h"
#include "Model/User.h"

static constexpr char TEST_USER_NAME[] = "user";
static constexpr char TEST_USER_SURNAME[] = "adminson";
static constexpr char TEST_USER_PASSWORD[] = "12341234";
static constexpr char TEST_USER_EMAIL[] = "test@mail.com";
static constexpr User::Role TEST_USER_ROLE = User::Role::USER;

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

BOOST_AUTO_TEST_CASE(FieldAPI)
{
	Poco::JSON::Object::Ptr jsonRequest = new Poco::JSON::Object;
	Poco::JSON::Object::Ptr jsonResponse;
	ResponseCode responseCode;
	std::string response;

	User user(TEST_USER_NAME, TEST_USER_SURNAME, TEST_USER_PASSWORD, TEST_USER_EMAIL, TEST_USER_ROLE);
	user.CreateSql();

	Agriculture agriculture(TEST_AGRICULTURE_NAME, TEST_AGRICULTURE_HMIN, TEST_AGRICULTURE_HMAX);
	agriculture.CreateSql();

	jsonRequest->set("token", user.GetToken());
	BOOST_CHECK_EQUAL(TestApi("/field/table", jsonRequest), R"({"table":[]})");

	Field create;
	jsonRequest->clear();
	jsonRequest->set("agriculture",	agriculture.GetId());
	jsonRequest->set("area",		TEST_FIELD_AREA);
	jsonRequest->set("cadastral",	TEST_FIELD_CADASTRAL);
	jsonRequest->set("token",		user.GetToken());
	response = TestApi("/field/create", jsonRequest);
	create.FromJsonString(response);
	BOOST_CHECK_EQUAL(create.GetAgricultureId(),agriculture.GetId());
	BOOST_CHECK_EQUAL(create.GetArea(),			TEST_FIELD_AREA);
	BOOST_CHECK_EQUAL(create.GetCadastral(),	TEST_FIELD_CADASTRAL);
	BOOST_CHECK_EQUAL(create.GetUserId(),		user.GetId());

	Field read1;
	jsonRequest->clear();
	jsonRequest->set("id",		create.GetId());
	jsonRequest->set("token",	user.GetToken());
	response = TestApi("/field/read", jsonRequest);
	read1.FromJsonString(response);
	BOOST_CHECK_EQUAL(read1.GetAgricultureId(),	agriculture.GetId());
	BOOST_CHECK_EQUAL(read1.GetArea(),			TEST_FIELD_AREA);
	BOOST_CHECK_EQUAL(read1.GetCadastral(),		TEST_FIELD_CADASTRAL);
	BOOST_CHECK_EQUAL(read1.GetUserId(),		user.GetId());

	jsonRequest->clear();
	jsonRequest->set("id",			read1.GetId());
	jsonRequest->set("agriculture",	agriculture.GetId());
	jsonRequest->set("area",		TEST_FIELD_AREA2);
	jsonRequest->set("token",		user.GetToken());
	response = TestApi("/field/update", jsonRequest);
	responseCode.FromJsonString(response);
	BOOST_CHECK_EQUAL((int)responseCode.GetCode(),	(int)ResponseCode::Code::SUCCESS);
	BOOST_CHECK_EQUAL(responseCode.GetMessage(),	"OK");

	Field read2;
	jsonRequest->clear();
	jsonRequest->set("id",		read1.GetId());
	jsonRequest->set("token",	user.GetToken());
	response = TestApi("/field/read", jsonRequest);
	read2.FromJsonString(response);
	BOOST_CHECK_EQUAL(read2.GetAgricultureId(),	agriculture.GetId());
	BOOST_CHECK_EQUAL(read2.GetArea(),			TEST_FIELD_AREA2);
	BOOST_CHECK_EQUAL(read2.GetCadastral(),		TEST_FIELD_CADASTRAL);
	BOOST_CHECK_EQUAL(read2.GetUserId(),		user.GetId());
	BOOST_CHECK_EQUAL(read2.GetMeasurementLog().size(), 0);

	jsonRequest->clear();
	jsonRequest->set("id",		read2.GetId());
	jsonRequest->set("token",	user.GetToken());
	for (int i = 0; i < 4; ++i)
	{
		IrrigationRecord irrigation;
		jsonRequest->set("humidity", TEST_IRRIGATION_HUMIDITIES[i]);
		response = TestApi("/field/irrigate", jsonRequest);
		irrigation.FromJsonString(response);
		BOOST_CHECK_EQUAL(irrigation.GetFieldId(),		read2.GetId());
		BOOST_CHECK_EQUAL(irrigation.GetHumidity(),		TEST_IRRIGATION_HUMIDITIES[i]);
		BOOST_CHECK_EQUAL((int)irrigation.GetDecission(),(int)TEST_IRRIGATION_DECISSIONS[i]);
	}

	Field read3;
	jsonRequest->clear();
	jsonRequest->set("id",		read2.GetId());
	jsonRequest->set("token",	user.GetToken());
	response = TestApi("/field/read", jsonRequest);
	read3.FromJsonString(response);
	BOOST_CHECK_EQUAL(read3.GetAgricultureId(),	agriculture.GetId());
	BOOST_CHECK_EQUAL(read3.GetArea(),			TEST_FIELD_AREA2);
	BOOST_CHECK_EQUAL(read3.GetCadastral(),		TEST_FIELD_CADASTRAL);
	BOOST_CHECK_EQUAL(read3.GetUserId(),		user.GetId());
	BOOST_CHECK_EQUAL(read3.GetMeasurementLog().size(), 4);

	jsonRequest->clear();
	jsonRequest->set("id",		read1.GetId());
	jsonRequest->set("token",	user.GetToken());
	response = TestApi("/field/delete", jsonRequest);
	responseCode.FromJsonString(response);
	BOOST_CHECK_EQUAL((int)responseCode.GetCode(),	(int)ResponseCode::Code::SUCCESS);
	BOOST_CHECK_EQUAL(responseCode.GetMessage(),	"OK");

	agriculture.DeleteSql();
	user.DeleteSql();
}
