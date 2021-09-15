#include "StringUtility.h"

#include <Poco/DigestEngine.h>
#include <Poco/MD5Engine.h>

#ifdef _WIN32
#include <Poco/TextConverter.h>
#include <Poco/UTF8Encoding.h>
#include <Poco/Windows1251Encoding.h>

std::string DecodeMessage(const std::string &src)
{
	std::string temp;
	Poco::UTF8Encoding utf8;
	Poco::Windows1251Encoding cp1251;
	Poco::TextConverter conv(utf8, cp1251);
	conv.convert(src, temp);
	return temp;
}

#endif // _WIN32
