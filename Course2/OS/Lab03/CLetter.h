#ifndef CLETTER_H
#define CLETTER_H

#include <cstdint>

class CLetter
{
public:
	explicit CLetter(const char* szMessage, uint8_t cSize);
	~CLetter();

	inline uint8_t		GetSize()		const { return m_cSize; }
	inline const char*	GetMessage()	const { return m_szMessage; }

private:
	uint8_t	m_cSize;
	char*	m_szMessage;
};

#endif // CLETTER_H
