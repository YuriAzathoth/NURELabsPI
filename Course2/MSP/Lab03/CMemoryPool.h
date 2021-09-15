#ifndef CMEMORYPOOL_H
#define CMEMORYPOOL_H

#include <cstdint>
#include <cstdlib>
#include <new>

template <typename T>
class CMemoryPool
{
	static constexpr size_t INITIAL_SIZE = 1;

public:
	CMemoryPool() :
		m_nCurSize(0),
		m_nMaxSize(INITIAL_SIZE)
	{
		m_pPool = (T*)malloc(sizeof(T) * INITIAL_SIZE);
	}

	~CMemoryPool() { free(m_pPool); }

	inline size_t	Size() const { return m_nCurSize; }
	inline T*		Last() const { return m_pPool + (m_nCurSize - 1); }

	CMemoryPool<T> &operator<<(const T &rSrc)
	{
		if (m_nCurSize >= m_nMaxSize)
		{
			m_nMaxSize *= 2;
			m_pPool = (T*)realloc(m_pPool, sizeof(T) * m_nMaxSize);
		}
		T* pCurrPos = m_pPool + m_nCurSize;
		new (pCurrPos) T(rSrc);
		++m_nCurSize;
		return *this;
	}

	CMemoryPool<T> &operator>>(const T &rSrc)
	{
		for (T* pFoundObj = m_pPool; pFoundObj <= Last(); pFoundObj++)
			if (*pFoundObj == rSrc)
			{
				*pFoundObj = *Last();
				--m_nCurSize;
			}
		return *this;
	}

	T &operator[] (size_t nPosition) { return *(m_pPool + nPosition); }

	void Shrink()
	{
		m_pPool = (T*)realloc(m_pPool, sizeof(T) * m_nCurSize);
		m_nMaxSize = m_nCurSize;
	}

private:
	T*			m_pPool;
	size_t		m_nCurSize;
	size_t		m_nMaxSize;
};

#endif // CMEMORYPOOL_H
