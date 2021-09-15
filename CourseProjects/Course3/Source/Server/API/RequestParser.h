#ifndef REQUESTPARSER_H
#define REQUESTPARSER_H

#include <string>

class RequestParser
{
public:
	RequestParser(const std::string &uri);

	const std::string &GetType() const noexcept { return type_; }
	const std::string &GetAction() const noexcept { return action_; }
	bool IsValid() const noexcept { return valid_; }

private:
	std::string type_;
	std::string action_;
	bool valid_;
};

#endif // REQUESTPARSER_H
