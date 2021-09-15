#ifndef SQLOBJECT_H
#define SQLOBJECT_H

#include <memory>
#include <string>
#include <Poco/Data/Session.h>
#include <Poco/Data/SessionPool.h>
#include <Poco/Tuple.h>

class SqlObject
{
public:
	SqlObject(int id = -1) : id_(id) {}
	virtual ~SqlObject() = default;

	void CreateSql();
	void ReadSql();
	void UpdateSql();
	void DeleteSql();

	int GetId() const noexcept { return id_; }

protected:
	virtual void CreateSqlRecord(Poco::Data::Session sql) = 0;
	virtual void ReadSqlRecord(Poco::Data::Session sql) = 0;
	virtual void UpdateSqlRecord(Poco::Data::Session sql) = 0;
	virtual void DeleteSqlRecord(Poco::Data::Session sql) = 0;

	Poco::Data::Session GetSqlSession() const;

	int id_;
};

#endif // SQLOBJECT_H
