#ifndef DATABASEUTILITY_H
#define DATABASEUTILITY_H

#include <string>
#include <wx/msgdlg.h>
#include <wx/string.h>
#include "nanodbc/nanodbc.h"

#define DEBUG_BEGIN try {
#define DEBUG_END } catch(std::exception &e) { wxMessageBox(wxString::Format("Exception in %s: %s\n", __func__, wxString::FromUTF8(e.what())), "An exception has occured!\n"); }

using nano_char = nanodbc::string::value_type;

template<typename T> const T* convert_wx_to_nano(const wxString &rsSource);
template<> const char16_t* convert_wx_to_nano<char16_t>(const wxString &rsSource)
{
	return reinterpret_cast<const char16_t*>(rsSource.wc_str());
}
template<> const wchar_t* convert_wx_to_nano<wchar_t>(const wxString &rsSource) { return rsSource.wc_str(); }
template<> const char* convert_wx_to_nano<char>(const wxString &rsSource)
{
	return reinterpret_cast<const char*>(rsSource.c_str().AsChar());
}

template<typename T> const wxString convert_nano_to_wx(const std::basic_string<T> &rsSource);
template<> const wxString convert_nano_to_wx<char16_t>(const std::u16string &rsSource)
{
	return reinterpret_cast<const wchar_t*>(rsSource.c_str());
}
template<> const wxString convert_nano_to_wx<wchar_t>(const std::wstring &rsSource) { return rsSource.c_str(); }
template<> const wxString convert_nano_to_wx<char>(const std::string &rsSource) { return rsSource.c_str(); }

const nano_char* wx_to_nano(const wxString &rsSource)
{
	return convert_wx_to_nano<nano_char>(rsSource);
}

wxString nano_to_wx(const nanodbc::string &rsSource)
{
	return convert_nano_to_wx<nano_char>(rsSource);
}

#endif // DATABASEUTILITY_H
