#include <cassert>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <sys/unistd.h>
#include "CLetter.h"
#include "CStorage.h"
using namespace std;

CStorage::CStorage(const char* szFilename) :
	m_nMsgCount(0),
	m_nCurrSize(0),
	m_nMaxSize(MAX_SIZE)
{
	m_szFileName = strdup(szFilename);
	Load();
}

CStorage::~CStorage()
{
	Save();
	ClearMessages();
	free(m_szFileName);
}

void CStorage::Load(const char* szFileName)
{
	int file = open(szFileName, O_RDWR);

	read(file, (void*)&m_nMsgCount,	sizeof(m_nMsgCount));
	read(file, (void*)&m_nCurrSize,	sizeof(m_nCurrSize));
	read(file, (void*)&m_nMaxSize,	sizeof(m_nMaxSize));

	m_Letters.reserve(m_nMsgCount);
	for (uint32_t i = 0; i < m_nMsgCount; i++)
	{
		uint8_t cSize;
		read(file, (void*)&cSize,			sizeof(cSize));

		char* szMessage = new char[cSize];
		for (uint8_t i = 0; i < cSize; i++)
			read(file, (void*)&szMessage[i],sizeof(char));

		m_Letters.push_back(new CLetter(szMessage, cSize));

		delete[] szMessage;
	}

	close(file);
}

void CStorage::Save(const char* szFileName) const
{
	int file = open(szFileName, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	write(file, (void*)&m_nMsgCount,	sizeof(m_nMsgCount));
	write(file, (void*)&m_nCurrSize,	sizeof(m_nCurrSize));
	write(file, (void*)&m_nMaxSize,		sizeof(m_nMaxSize));

	for (auto it : m_Letters)
	{
		uint8_t cSize = it->GetSize();
		const char* szMessage = it->GetMessage();

		write(file, (void*)&cSize,				sizeof(cSize));
		for (uint8_t i = 0; i < cSize; i++)
			write(file, (void*)&szMessage[i],	sizeof(char));
	}

	close(file);
}

void CStorage::SaveBackup() const
{
	char* szBackupName = new char[strlen(m_szFileName) + 5];
	strcpy(szBackupName, m_szFileName);
	strcat(szBackupName, ".bak");

	Save();
	Save(szBackupName);

	delete[] szBackupName;
}

void CStorage::LoadBackup()
{
	char* szBackupName = new char[strlen(m_szFileName) + 5];
	strcpy(szBackupName, m_szFileName);
	strcat(szBackupName, ".bak");

	Load(szBackupName);

	delete[] szBackupName;
}

void CStorage::PushMessage(const char* szMessage)
{
	if (!szMessage[0])
		throw logic_error("ОШИБКА: Введено пустое сообщение!");

	const uint8_t cSize = (uint8_t)strlen(szMessage);

	if (m_nCurrSize + (uint32_t)cSize > m_nMaxSize)
		throw logic_error("ОШИБКА: Длина сообщения больше оставшейся длины!");

	m_Letters.push_back(new CLetter(szMessage, cSize));
	m_nMsgCount++;
	m_nCurrSize += cSize;
}

void CStorage::RemoveMessage(uint32_t nMessageId)
{
	if (nMessageId > m_nMsgCount)
		throw logic_error("ОШИБКА: Введённое число больше колличества писем!");
	auto it = m_Letters.begin() + nMessageId;
	m_nCurrSize -= (*it)->GetSize();
	m_nMsgCount--;
	m_Letters.erase(it);
}

void CStorage::ClearMessages()
{
	while (!m_Letters.empty())
	{
		delete m_Letters.back();
		m_Letters.pop_back();
	}
	m_nMsgCount = 0;
	m_nCurrSize = 0;
}
