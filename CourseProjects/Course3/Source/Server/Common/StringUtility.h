#ifndef STRINGUTILITY_H
#define STRINGUTILITY_H

#ifdef _WIN32
#include <string>

std::string DecodeMessage(const std::string &src);
#else
#define DecodeMessage(MSG) MSG
#endif // __WIN32

#endif // STRINGUTILITY_H
