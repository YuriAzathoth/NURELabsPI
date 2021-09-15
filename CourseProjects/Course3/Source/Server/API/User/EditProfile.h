#ifndef EDITPROFILE_H
#define EDITPROFILE_H

#include "API/RequestHandler.h"

class EditProfile : public RequestHandler
{
private:
	std::string ProcessRequest() override final;
	void ValidateData() const override final;
	void LoadFromJson(const Poco::JSON::Object::Ptr object) override final;

	std::string oldEmail_;
	std::string oldPassword_;
	std::string surname_;
	std::string name_;
	std::string password_;
	std::string email_;
};

#endif // EDITPROFILE_H
