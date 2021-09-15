#include "PCH.h"
#include "CookiesManager.h"

CookiesManager::CookiesManager(const Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) :
	m_request(request),
	m_response(response)
{
	m_request.getCookies(m_cookies);
}

std::string CookiesManager::Get(const std::string &name) const
{
	auto it = m_cookies.find(name);
	if (it != m_cookies.end())
		return it->second;
	return "";
}

std::string CookiesManager::Get(const std::string &name, const std::string &defval)
{
	auto it = m_cookies.find(name);
	if (it != m_cookies.end())
		return it->second;
	Set(name, defval);
	return defval;
}

void CookiesManager::Set(const std::string &name, const std::string &value)
{
	Poco::Net::HTTPCookie cookie(name, value);
	cookie.setPath("/");
	m_response.addCookie(cookie);
	if (m_cookies.has(name))
		m_cookies.set(name, value);
	else
		m_cookies.add(name, value);
}
