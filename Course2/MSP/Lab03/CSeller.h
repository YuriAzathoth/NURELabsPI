#ifndef CSELLER_H
#define CSELLER_H

#include "CCar.h"
#include "CMemoryPool.h"

class CSeller
{
public:
	size_t	GetCarCount() const		{ return m_Cars.Size(); }
	CCar	&GetCar(size_t nIndex)	{ return m_Cars[nIndex]; }

	CSeller	&operator+(const CCar &rCar) { m_Cars << rCar; return *this; };
	CSeller &operator-(const CCar &rCar) { m_Cars >> rCar; return *this; }

private:
	CMemoryPool<CCar> m_Cars;
};

#endif // CSELLER_H
