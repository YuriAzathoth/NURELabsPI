#include <cstdlib>
#include <cstring>
#include "CLetter.h"

CLetter::CLetter(const char* szMessage, uint8_t cSize) :
	m_cSize(cSize)
{
	m_szMessage = (char*)calloc(sizeof(char), m_cSize);
	memcpy(m_szMessage, szMessage, (size_t)m_cSize);
}

CLetter::~CLetter()
{
	free(m_szMessage);
}
