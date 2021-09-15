#ifndef IRECEIVER_H
#define IRECEIVER_H

#include <iostream>
#include "IAddress.h"
#include "IPrintable.h"
using namespace std;

class IReceiver : public IAddress, virtual public IPrintable
{
public:
	IReceiver(const char* szAddress) : IAddress(szAddress) {}
	~IReceiver() {}

	virtual void Print() const override
	{
		cout << "Receiver:\t" << GetAddress() << endl;
	}
};

#endif // IRECEIVER_H
