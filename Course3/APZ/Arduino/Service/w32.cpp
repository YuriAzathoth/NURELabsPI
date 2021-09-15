#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "w32.h"

#define ARDUINO_WAIT_TIME 1000

Serial::Serial(char* port) : m_connected(false)
{
	m_serial = CreateFileA(port, GENERIC_READ | GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

	if (m_serial != INVALID_HANDLE_VALUE)
	{
		DCB dcb_serial_params = {0};
		if (GetCommState(m_serial, &dcb_serial_params))
		{
			dcb_serial_params.BaudRate	= CBR_9600;
			dcb_serial_params.ByteSize	= 8;
			dcb_serial_params.StopBits	= ONESTOPBIT;
			dcb_serial_params.Parity	= NOPARITY;
			if (GetCommState(m_serial, &dcb_serial_params))
			{
				m_connected = true;
				Sleep(ARDUINO_WAIT_TIME);
			}
			else
			{
				printf("ERROR: Could not set Serial Port parameters.");
				exit(4);
			}
		}
		else
		{
			printf("ERROR: Failed to get current serial parameters.");
			exit(3);
		}
	}
	else
	{
		if (GetLastError() == ERROR_FILE_NOT_FOUND)
		{
			printf("ERROR: Handle was not attached. Reason: %s not available.\n", port);
			exit(1);
		}
		else
		{
			printf("ERROR: Unknown error.\n");
			exit(2);
		}
	}
}

Serial::~Serial()
{
	if (m_connected)
	{
		m_connected = false;
		CloseHandle(m_serial);
	}
}

int Serial::ReadData(char* buffer, uint32_t nbchar)
{
	DWORD bytes_read;
	uint32_t bytes_to_read;
	ClearCommError(m_serial, &m_errors, &m_status);
	if (m_status.cbInQue)
	{
		if (m_status.cbInQue > nbchar)
			bytes_to_read = nbchar;
		else
			bytes_to_read = m_status.cbInQue;
		if (ReadFile(m_serial, buffer, bytes_to_read, &bytes_read, nullptr) && bytes_read)
			return bytes_read;
	}
	return -1;
}

bool Serial::WriteData(char* buffer, uint32_t nbchar)
{
	DWORD bytes_write;
	if (WriteFile(m_serial, (void*)buffer, nbchar, &bytes_write, nullptr))
	{
		ClearCommError(m_serial, &m_errors, &m_status);
		return true;
	}
	else
		return false;
}
