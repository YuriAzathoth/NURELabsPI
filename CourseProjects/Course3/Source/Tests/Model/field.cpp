#include <regex>
#include <sstream>
#include <stdexcept>
#include <boost/test/unit_test.hpp>
#include <Poco/DateTime.h>
#include <Poco/Timestamp.h>
#include "Model/Field.h"
#include "Model/User.h"

static constexpr char TEST_USER_NAME[] = "user";
static constexpr char TEST_USER_SURNAME[] = "adminson";
static constexpr char TEST_USER_PASSWORD[] = "1234";
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

BOOST_AUTO_TEST_SUITE(FieldTest)

BOOST_AUTO_TEST_CASE(SQL)
{
	Poco::Timestamp nowDate;
	Poco::DateTime now(nowDate);
	Poco::DateTime date;

	User user(TEST_USER_NAME, TEST_USER_SURNAME, TEST_USER_PASSWORD, TEST_USER_EMAIL, TEST_USER_ROLE);
	user.CreateSql();

	Agriculture agriculture(TEST_AGRICULTURE_NAME, TEST_AGRICULTURE_HMIN, TEST_AGRICULTURE_HMAX);
	agriculture.CreateSql();

	Field create(TEST_FIELD_CADASTRAL, agriculture.GetId(), user.GetId(), TEST_FIELD_AREA);
	create.CreateSql();

	const int id = create.GetId();

	Field field1(id);

	BOOST_CHECK_EQUAL(field1.GetUserId(),		user.GetId());
	BOOST_CHECK_EQUAL(field1.GetCadastral(),	TEST_FIELD_CADASTRAL);
	BOOST_CHECK_EQUAL(field1.GetArea(),			TEST_FIELD_AREA);

	BOOST_CHECK_EQUAL(field1.GetMeasurementLog().size(), 0);

	for (size_t i = 0; i < 4; ++i)
	{
		const IrrigationRecord record = field1.DoMeasurement(TEST_IRRIGATION_HUMIDITIES[i]);
		BOOST_CHECK_EQUAL(static_cast<int>(record.GetDecission()),
						  static_cast<int>(TEST_IRRIGATION_DECISSIONS[i]));
	}

	int i = 0;
	for (const auto &record : field1.GetMeasurementLog())
	{
		BOOST_CHECK_EQUAL(record.second.GetFieldId(),	id);
		BOOST_CHECK_EQUAL(record.second.GetHumidity(),	TEST_IRRIGATION_HUMIDITIES[i]);
		BOOST_CHECK_EQUAL((int)record.second.GetDecission(), (int)TEST_IRRIGATION_DECISSIONS[i]);

		date = record.second.GetDate();
		BOOST_CHECK_EQUAL(date.day(),	now.day());
		BOOST_CHECK_EQUAL(date.month(),	now.month());
		BOOST_CHECK_EQUAL(date.year(),	now.year());

		++i;
	}

	field1.SetArea(TEST_FIELD_AREA2);
	field1.UpdateSql();

	Field field2(id);
	BOOST_CHECK_EQUAL(field1.GetUserId(),		user.GetId());
	BOOST_CHECK_EQUAL(field1.GetCadastral(),	TEST_FIELD_CADASTRAL);
	BOOST_CHECK_EQUAL(field2.GetArea(),			TEST_FIELD_AREA2);

	field1.DeleteSql();
	agriculture.DeleteSql();
	user.DeleteSql();
}

BOOST_AUTO_TEST_SUITE_END()
