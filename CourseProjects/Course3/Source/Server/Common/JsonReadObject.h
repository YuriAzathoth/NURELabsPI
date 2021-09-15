#ifndef JSONREADOBJECT_H
#define JSONREADOBJECT_H

#include <string>
#include <Poco/JSON/Object.h>

class JsonReadObject
{
public:
	JsonReadObject() = default;
	virtual ~JsonReadObject() = default;

	void FromJsonString(std::string json);
	void FromJsonObject(Poco::JSON::Object::Ptr json);

private:
	virtual void LoadFromJson(const Poco::JSON::Object::Ptr object) = 0;
};

#endif // JSONREADOBJECT_H
