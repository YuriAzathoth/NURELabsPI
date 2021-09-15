#include <Poco/DigestEngine.h>
#include <Poco/MD5Engine.h>
#include "Common/ServerException.h"
#include "User.h"

#define SQL_CREATE R"(INSERT INTO "users"("name", "surname", "password", "email", "role") VALUES(?, ?, ?, ?, ?) RETURNING "id")"
#define SQL_READ_TOKEN R"(SELECT "id", "name", "surname", "email", "role" FROM "get_user_id_by_token"(?))"
#define SQL_READ_ID R"(SELECT "name", "surname", "email", "role" FROM "users" WHERE "id" = ?)"
#define SQL_UPDATE R"(UPDATE "users" SET "name" = ?, "surname" = ?, "email" = ? WHERE "id" = ?)"
#define SQL_UPDATE_PASSWORD R"(UPDATE "users" SET "password" = ? WHERE "id" = ?)"
#define SQL_DELETE R"(DELETE FROM "users" WHERE "id" = ?)"

using namespace Poco::Data::Keywords;

User::User(int id) :
	SqlObject(id)
{
	ReadSql();
}

User::User(const std::string &token) :
	token_(token)
{
	ReadSql();
}

User::User(const std::string &email, const std::string &password) :
	email_(email)
{
	CreateToken(HashText(password));
	ReadSql();
}

User::User(const std::string &name,
		   const std::string &surname,
		   const std::string &password,
		   const std::string &email,
		   Role role) :
	name_(name),
	surname_(surname),
	password_(HashText(password)),
	email_(email),
	role_(static_cast<int>(role))
{
	CreateToken(password_);
}

User::User(const Poco::JSON::Object::Ptr json)
{
	FromJsonObject(json);
}

void User::CreateSqlRecord(Poco::Data::Session sql)
{
	sql << SQL_CREATE, use(name_), use(surname_), use(password_), use(email_),
		use(role_), into(id_), now;
	password_.clear();
}

void User::ReadSqlRecord(Poco::Data::Session sql)
{
	if (GetId() > 0 && token_.empty())
		sql << SQL_READ_ID, use(id_), into(name_), into(surname_), into(email_),
			into(role_), now;
	else
		sql << SQL_READ_TOKEN, use(token_), into(id_), into(name_),
			into(surname_), into(email_), into(role_), now;

	if (surname_.empty() && name_.empty())
		throw ServerException(ServerException::Code::ACCESS_DENIED,
							  "Invalid user email or password.");
}

void User::UpdateSqlRecord(Poco::Data::Session sql)
{
	sql << SQL_UPDATE, use(name_), use(surname_), use(email_), use(id_), now;
	if (!password_.empty())
	{
		sql << SQL_UPDATE_PASSWORD, use(password_), use(id_), now;
		CreateToken(password_);
		password_.clear();
	}
}

void User::DeleteSqlRecord(Poco::Data::Session sql)
{
	sql << SQL_DELETE, use(id_), now;
}

void User::LoadFromJson(const Poco::JSON::Object::Ptr object)
{
	email_	= object->getValue<std::string>("email");
	name_	= object->getValue<std::string>("name");
	role_	= object->getValue<int>("role");
	surname_= object->getValue<std::string>("surname");
	token_	= object->getValue<std::string>("token");
}

void User::SaveToJson(Poco::JSON::Object::Ptr object) const
{
	object->set("email",	email_);
	object->set("name",		name_);
	object->set("role",		role_);
	object->set("surname",	surname_);
	object->set("token",	token_);
}

void User::CreateToken(const std::string &password)
{
	token_ = HashText(email_ + "|" + password);
}

std::string User::HashText(const std::string &text)
{
	Poco::MD5Engine md5engine;
	md5engine.update(text);
	return Poco::DigestEngine::digestToHex(md5engine.digest());
}
