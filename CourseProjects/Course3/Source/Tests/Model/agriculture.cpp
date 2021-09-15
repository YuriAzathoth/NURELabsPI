#include <sstream>
#include <stdexcept>
#include <boost/test/unit_test.hpp>
#include "Model/Agriculture.h"

static constexpr char TEST_AGRICULTURE_NAME[] = "wheat";
static constexpr short TEST_AGRICULTURE_HMIN = 24;
static constexpr short TEST_AGRICULTURE_HMAX = 32;

static constexpr char TEST_AGRICULTURE_NAME2[] = "reese";
static constexpr short TEST_AGRICULTURE_HMIN2 = 60;
static constexpr short TEST_AGRICULTURE_HMAX2 = 80;

static constexpr char TEST_AGRICULTURE_JSON[] = R"({"humidity_max":32,"humidity_min":24,"id":-1,"name":"wheat"})";

BOOST_AUTO_TEST_SUITE(AgricultureTest)

BOOST_AUTO_TEST_CASE(Sql)
{
	Agriculture create(TEST_AGRICULTURE_NAME, TEST_AGRICULTURE_HMIN, TEST_AGRICULTURE_HMAX);
	create.CreateSql();
	const int id = create.GetId();

	Agriculture agriculture1(id);
	BOOST_CHECK_EQUAL(agriculture1.GetName(),			TEST_AGRICULTURE_NAME);
	BOOST_CHECK_EQUAL(agriculture1.GetHumidityMin(),	TEST_AGRICULTURE_HMIN);
	BOOST_CHECK_EQUAL(agriculture1.GetHumidityMax(),	TEST_AGRICULTURE_HMAX);

	agriculture1.SetName(TEST_AGRICULTURE_NAME2);
	agriculture1.SetHumidityMin(TEST_AGRICULTURE_HMIN2);
	agriculture1.SetHumidityMax(TEST_AGRICULTURE_HMAX2);
	agriculture1.UpdateSql();

	Agriculture agriculture2(id);
	BOOST_CHECK_EQUAL(agriculture2.GetName(),			TEST_AGRICULTURE_NAME2);
	BOOST_CHECK_EQUAL(agriculture2.GetHumidityMin(),	TEST_AGRICULTURE_HMIN2);
	BOOST_CHECK_EQUAL(agriculture2.GetHumidityMax(),	TEST_AGRICULTURE_HMAX2);

	agriculture1.DeleteSql();
}

BOOST_AUTO_TEST_CASE(Json)
{
	Agriculture toJson(TEST_AGRICULTURE_NAME, TEST_AGRICULTURE_HMIN, TEST_AGRICULTURE_HMAX);
	BOOST_CHECK_EQUAL(toJson.ToJsonString(), TEST_AGRICULTURE_JSON);

	Agriculture fromJson;
	fromJson.FromJsonString(TEST_AGRICULTURE_JSON);
	BOOST_CHECK_EQUAL(fromJson.GetName(),			TEST_AGRICULTURE_NAME);
	BOOST_CHECK_EQUAL(fromJson.GetHumidityMin(),	TEST_AGRICULTURE_HMIN);
	BOOST_CHECK_EQUAL(fromJson.GetHumidityMax(),	TEST_AGRICULTURE_HMAX);
	BOOST_CHECK_EQUAL(fromJson.GetId(),				-1);
}

BOOST_AUTO_TEST_SUITE_END()
