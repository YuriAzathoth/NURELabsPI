#include "PCH.h"
#include "DatabaseSystem.h"

DatabaseSystem::DatabaseSystem()
{
	Poco::Data::ODBC::Connector::registerConnector();
	const Poco::Util::LayeredConfiguration &config = Poco::Util::Application::instance().config();
	m_connstr	= config.getString("Database.connstr");
	m_dbtype	= config.getString("Database.type");
}
