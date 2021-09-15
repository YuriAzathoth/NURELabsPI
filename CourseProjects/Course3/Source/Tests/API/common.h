#ifndef TESTS_COMMON_H
#define TESTS_COMMON_H

#include <string>
#include <Poco/JSON/Object.h>

std::string TestApi(const std::string &handler, const Poco::JSON::Object::Ptr data);

#endif // TESTS_COMMON_H
