#ifndef READAGRICULTURE_H
#define READAGRICULTURE_H

#include "API/RequestHandler.h"

class ReadAgriculture : public RequestHandler
{
private:
	std::string ProcessRequest() override final;
	void LoadFromJson(const Poco::JSON::Object::Ptr object) override final;

	int id_;
};

#endif // READAGRICULTURE_H
