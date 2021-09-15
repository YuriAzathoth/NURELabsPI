#ifndef UPDATEFIELD_H
#define UPDATEFIELD_H

#include "API/RequestHandler.h"

class UpdateField : public RequestHandler
{
private:
	std::string ProcessRequest() override final;
	void ValidateData() const override final;
	void LoadFromJson(const Poco::JSON::Object::Ptr object) override final;

	std::string token_;
	int agriculture_;
	int id_;
	short area_;
};

#endif // UPDATEFIELD_H
