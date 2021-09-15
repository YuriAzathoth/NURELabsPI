#ifndef USERSTABLE_H
#define USERSTABLE_H

#include <string>
#include <vector>
#include "Common/SqlObject.h"
#include "User.h"

class UsersTable : public SqlObject
{
public:
	explicit UsersTable(User::Role role);

	const std::vector<User> &GetTable() const noexcept { return table_; }
	size_t GetSize() const noexcept { return table_.size(); }

private:
	void ReadSqlRecord(Poco::Data::Session sql) override final;
	void CreateSqlRecord(Poco::Data::Session) override final {}
	void UpdateSqlRecord(Poco::Data::Session) override final {}
	void DeleteSqlRecord(Poco::Data::Session) override final {}

	std::vector<User> table_;
	short role_;
};

#endif // USERSTABLE_H
