#include "UsersTable.h"

#define SQL_READ R"(SELECT "id" FROM "users" WHERE "role" = ?)"

using namespace Poco::Data::Keywords;

UsersTable::UsersTable(User::Role role) :
	role_(static_cast<short>(role))
{
	ReadSql();
}

void UsersTable::ReadSqlRecord(Poco::Data::Session sql)
{
	std::vector<int> ids;
	sql << SQL_READ, use(role_), into(ids), now;
	table_.reserve(ids.size());
	for (int id : ids)
		table_.emplace_back(id);
}
