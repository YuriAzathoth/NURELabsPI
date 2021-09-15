#ifndef IADDRESS_H
#define IADDRESS_H

#include <cstdlib>
#include <cstring>
using namespace std;

class IAddress
{
public:
	IAddress(const char* szAddress) : m_szAddress(strdup(szAddress)) {}
	virtual ~IAddress()	{ free(m_szAddress); }

	const char* GetAddress() const { return m_szAddress; }

private:
	char* m_szAddress;
};

#endif // IADDRESS_H
