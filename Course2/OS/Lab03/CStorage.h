#ifndef CSTORAGE_H
#define CSTORAGE_H

#include <cstdint>
#include <vector>

class CLetter;

class CStorage
{
public:
	typedef std::vector<CLetter*> TLetters;

	explicit CStorage(const char* szFilename);
	~CStorage();

	void Load(const char* szFileName);
	void Save(const char* szFileName) const;

	inline void Load()			{ Load(m_szFileName); }
	inline void Save() const	{ Save(m_szFileName); }

	void SaveBackup() const;
	void LoadBackup();

    void PushMessage	(const char* szMessage);
    void RemoveMessage	(uint32_t nMessageId);
    void ClearMessages	();

    inline uint32_t	GetMessagesCount()		const { return m_nMsgCount; }
    inline uint32_t	GetCurrentSize()		const { return m_nCurrSize; }
    inline uint32_t	GetMaxSize()			const { return m_nMaxSize; }
    inline const	TLetters &GetLetters()	const { return m_Letters; }

private:
	char*		m_szFileName;
	uint32_t	m_nMsgCount;
	uint32_t	m_nCurrSize;
	uint32_t	m_nMaxSize;
	TLetters	m_Letters;

	static constexpr uint32_t MAX_SIZE = 2048;
};

#endif // CSTORAGE_H
