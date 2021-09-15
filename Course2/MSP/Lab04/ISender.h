#ifndef ISENDER_H
#define ISENDER_H

#include <iostream>
#include "IAddress.h"
#include "IPrintable.h"
using namespace std;

class ISender : public IAddress, virtual public IPrintable
{
public:
	ISender(const char* szAddress) : IAddress(szAddress) {}
	~ISender() {}

	virtual void Print() const override
	{
		cout << "Sender:\t\t" << GetAddress() << endl;
	}
};

#endif // ISENDER_H
