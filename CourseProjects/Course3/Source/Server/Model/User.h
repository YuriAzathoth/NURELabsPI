#ifndef USER_H
#define USER_H

#include <string>
#include "Common/JsonObject.h"
#include "Common/SqlObject.h"

class User : public JsonObject, public SqlObject
{
public:
	enum class Role { ADMIN, USER, EMPLOYEE };

	User() = default;
	explicit User(int id);
	explicit User(const std::string &token);
	User(const std::string &email, const std::string &password);
	User(const std::string &name,
		 const std::string &surname,
		 const std::string &password,
		 const std::string &email,
		 Role role);
	explicit User(const Poco::JSON::Object::Ptr json);

	void SetName(const std::string &name) { name_ = name; }
	void SetSurname(const std::string &surname) { surname_ = surname; }
	void SetPassword(const std::string &password) { password_ = HashText(password); }
	void SetEmail(const std::string &email) { email_ = email; }

	const std::string &GetName() const noexcept { return name_; }
	const std::string &GetSurname() const noexcept { return surname_; }
	const std::string &GetEmail() const noexcept { return email_; }
	const std::string &GetToken() const noexcept { return token_; }
	Role GetRole() const noexcept { return static_cast<Role>(role_); }

private:
	void CreateSqlRecord(Poco::Data::Session sql) override final;
	void ReadSqlRecord(Poco::Data::Session sql) override final;
	void UpdateSqlRecord(Poco::Data::Session sql) override final;
	void DeleteSqlRecord(Poco::Data::Session sql) override final;

	void LoadFromJson(const Poco::JSON::Object::Ptr object) override final;
	void SaveToJson(Poco::JSON::Object::Ptr object) const override final;

	void CreateToken(const std::string &password);

	std::string name_;
	std::string surname_;
	std::string password_;
	std::string email_;
	std::string token_;
	int role_;

	static std::string HashText(const std::string &text);
};

#endif // USER_H
