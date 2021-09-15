#ifndef DATABASESYSTEM_H
#define DATABASESYSTEM_H

class DatabaseSystem
{
public:
	DatabaseSystem();
	Poco::Data::Session NewSession() const
	{
		return Poco::Data::SessionFactory::instance().create(m_dbtype, m_connstr);
	}

private:
	std::string m_connstr;
	std::string m_dbtype;
};

#endif // DATABASESYSTEM_H
