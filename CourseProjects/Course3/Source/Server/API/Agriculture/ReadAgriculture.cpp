#include "ReadAgriculture.h"
#include "Model/Agriculture.h"

std::string ReadAgriculture::ProcessRequest()
{
	Agriculture agriculture(id_);
	return agriculture.ToJsonString();
}

void ReadAgriculture::LoadFromJson(const Poco::JSON::Object::Ptr object)
{
	id_ = object->getValue<int>("id");
}
