#define BOOST_TEST_MODULE UnitTests
#include <cstdlib>
#include <boost/test/unit_test.hpp>
#include <Poco/Data/ODBC/Connector.h>
#include <Poco/Util/ServerApplication.h>

class GlobalFixture
{
public:
	void setup()
	{
		setlocale(LC_ALL, "");
		Poco::Util::Application::instance().loadConfiguration("../share/Config/settings.properties");
		Poco::Data::ODBC::Connector::registerConnector();
	}
	void teardown() {}
private:
	Poco::Util::ServerApplication app;
};

BOOST_TEST_GLOBAL_FIXTURE(GlobalFixture);
