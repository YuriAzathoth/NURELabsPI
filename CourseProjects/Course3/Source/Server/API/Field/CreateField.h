#ifndef CREATEFIELD_H
#define CREATEFIELD_H

#include "API/RequestHandler.h"

class CreateField : public RequestHandler
{
private:
	std::string ProcessRequest() override final;
	void ValidateData() const override final;
	void LoadFromJson(const Poco::JSON::Object::Ptr object) override final;

	std::string token_;
	std::string cadastral_;
	int agriculture_;
	short area_;
};

#endif // CREATEFIELD_H
