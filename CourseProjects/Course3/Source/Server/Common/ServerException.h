#ifndef SERVEREXCEPTION_H
#define SERVEREXCEPTION_H

#include <exception>
#include <string>
#include "Model/ResponseCode.h"

class ServerException : public std::exception
{
public:
	using Code = ResponseCode::Code;

	ServerException(Code code, const std::string &message) :
		code_(code, message)
	{
	}

	virtual ~ServerException() = default;

	const std::string ToJson() const
	{
		return code_.ToJsonString();
	}

	const char* what() const noexcept override
	{
		return code_.GetMessage().c_str();
	}

private:
	ResponseCode code_;
};

#endif // SERVEREXCEPTION_H
