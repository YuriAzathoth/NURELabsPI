#ifndef CCAR_H
#define CCAR_H

#include <cstdint>
#include <cstdlib>
#include <cstring>

class CCar
{
public:
	CCar(const char* szModel)	: m_nPrice(0)				{ m_szModel = strdup(szModel); }
	CCar(const CCar &rRhs) 		: m_nPrice(rRhs.m_nPrice)	{ m_szModel = strdup(rRhs.m_szModel); }

	~CCar() { std::free(m_szModel); }

    const char*		GetModel() const			{ return m_szModel; }
    const uint32_t	GetPrice() const			{ return m_nPrice; }
    const void		SetPrice(uint32_t nPrice)	{ m_nPrice = nPrice; }

	void operator=  (const CCar &rRhs) { std::strcpy(m_szModel, rRhs.m_szModel); }
	bool operator== (const CCar &rRhs) { return !std::strcmp(m_szModel, rRhs.m_szModel); }

private:
	char*		m_szModel;
	uint32_t	m_nPrice;
};

#endif // CCAR_H
