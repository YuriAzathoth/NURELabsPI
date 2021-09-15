#ifndef UTF8UTIL_H
#define UTF8UTIL_H

#ifdef __WIN32
static void ToUtf8(std::string &src)
{
	Poco::Windows1251Encoding enc_win;
	Poco::UTF8Encoding enc_utf8;
	Poco::TextConverter conv(enc_win, enc_utf8);
	std::string temp;
	conv.convert(src, temp);
	src = temp;
}
static void FromUtf8(std::string &src)
{
	Poco::UTF8Encoding enc_utf8;
	Poco::Windows1251Encoding enc_win;
	Poco::TextConverter conv(enc_utf8, enc_win);
	std::string temp;
	conv.convert(src, temp);
	src = temp;
}
#else
static void ToUtf8(std::string&) {}
static void FromUtf8(std::string&) {}
#endif // __WIN32

#endif // UTF8UTIL_H
