#ifndef JSONWRITEOBJECT_H
#define JSONWRITEOBJECT_H

#include <string>
#include <Poco/JSON/Object.h>

class JsonWriteObject
{
public:
	JsonWriteObject() = default;
	virtual ~JsonWriteObject() = default;

	std::string ToJsonString() const;
	Poco::JSON::Object::Ptr ToJsonObject() const;

private:
	virtual void SaveToJson(Poco::JSON::Object::Ptr object) const = 0;
};

#endif // JSONWRITEOBJECT_H
