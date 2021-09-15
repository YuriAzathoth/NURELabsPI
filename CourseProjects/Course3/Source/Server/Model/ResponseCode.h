#ifndef RESPONSECODE_H
#define RESPONSECODE_H

#include <vector>
#include "Common/JsonObject.h"

class ResponseCode : public JsonObject
{
public:
	enum class Code
	{
		SUCCESS,
		INTERNAL_ERROR,
		INVALID_REQUEST,
		INVALID_ID,
		INVALID_DATA,
		ACCESS_DENIED
	};

	ResponseCode() = default;
	ResponseCode(Code code, const std::string &message);

	Code GetCode() const noexcept { return static_cast<Code>(code_); }
	const std::string &GetMessage() const noexcept { return message_; }

	static std::string GetJson(Code code, const std::string &message);

private:
	void LoadFromJson(const Poco::JSON::Object::Ptr object) override final;
	void SaveToJson(Poco::JSON::Object::Ptr object) const override final;

	std::string message_;
	int code_;
};

#endif // RESPONSECODE_H
