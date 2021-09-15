#ifndef JSONOBJECT_H
#define JSONOBJECT_H

#include "JsonReadObject.h"
#include "JsonWriteObject.h"

class JsonObject :
	public JsonReadObject,
	public JsonWriteObject
{
public:
	JsonObject() = default;
	virtual ~JsonObject() = default;
};

#endif // JSONOBJECT_H
