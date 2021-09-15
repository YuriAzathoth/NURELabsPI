#ifndef ICOOKIEDEPENDENTOBJECT_H
#define ICOOKIEDEPENDENTOBJECT_H

class CookiesManager;

class ICookieDependentObject
{
public:
	ICookieDependentObject(CookiesManager &cookies) : m_cookies(cookies) {}
protected:
	CookiesManager &GetCookies() noexcept { return m_cookies; }
private:
	CookiesManager &m_cookies;
};

#endif // ICOOKIEDEPENDENTOBJECT_H
