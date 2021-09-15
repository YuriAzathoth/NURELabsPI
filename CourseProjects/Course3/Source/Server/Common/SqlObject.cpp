#include <Poco/Data/DataException.h>
#include <Poco/Util/Application.h>
#include <Poco/Util/LayeredConfiguration.h>
#include "Common/ServerException.h"
#include "Common/StringUtility.h"
#include "SqlObject.h"

static std::unique_ptr<Poco::Data::SessionPool> g_SessionPool;

void SqlObject::CreateSql()
{
	try
	{
		CreateSqlRecord(GetSqlSession());
	}
	catch (Poco::Exception &e)
	{
		throw std::runtime_error(DecodeMessage(e.message()));
	}
}

void SqlObject::ReadSql()
{
	try
	{
		ReadSqlRecord(GetSqlSession());
	}
	catch (Poco::Exception &e)
	{
		throw std::runtime_error(DecodeMessage(e.message()));
	}
}

void SqlObject::UpdateSql()
{
	try
	{
		UpdateSqlRecord(GetSqlSession());
	}
	catch (Poco::Exception &e)
	{
		throw std::runtime_error(DecodeMessage(e.message()));
	}
}

void SqlObject::DeleteSql()
{
	try
	{
		DeleteSqlRecord(GetSqlSession());
	}
	catch (Poco::Data::DataException &e)
	{
		throw std::runtime_error(DecodeMessage(e.message()));
	}
}

Poco::Data::Session SqlObject::GetSqlSession() const
{
	if (!g_SessionPool.get())
	{
		const auto &config = Poco::Util::Application::instance().config();
		g_SessionPool = std::make_unique<Poco::Data::SessionPool>(config.getString("Database.type"),
						config.getString("Database.connstr"));
	}
	return g_SessionPool->get();
}
