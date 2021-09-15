#include <Poco/StringTokenizer.h>
#include "RequestParser.h"

#define API_HANDLER "api"

enum
{
	POSITION_API_MARK = 1,
	POSITION_TYPE,
	POSITION_ACTION
};

RequestParser::RequestParser(const std::string &uri) :
	valid_(false)
{
	Poco::StringTokenizer tokenizer(uri, "/");

	if (tokenizer.count() >= 1)
		valid_ = tokenizer[POSITION_API_MARK] == API_HANDLER;

	if (!valid_)
		return;

	if (tokenizer.count() >= 2)
		type_ = tokenizer[POSITION_TYPE];

	if (tokenizer.count() >= 3)
		action_ = tokenizer[POSITION_ACTION];
}
