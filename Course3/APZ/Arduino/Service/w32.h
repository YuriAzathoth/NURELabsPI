#ifndef W32_H
#define W32_H

#include <cstdint>
#include <windows.h>

class Serial
{
public:
	Serial(char* port);
	~Serial();
	int ReadData(char* buffer, uint32_t nbchar);
	bool WriteData(char* buffer, uint32_t nbchar);

	bool IsConnected() const noexcept
	{
		return m_connected;
	}

private:
	COMSTAT	m_status;
	DWORD	m_errors;
	HANDLE	m_serial;
	bool	m_connected;
};

#endif // W32_H
