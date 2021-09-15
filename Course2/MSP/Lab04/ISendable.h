#ifndef ISENDABLE_H
#define ISENDABLE_H

#include <iostream>
#include "IReceiver.h"
#include "ISender.h"
using namespace std;

class ISendable : public ISender, public IReceiver
{
public:
	ISendable(const char* szSender, const char* szReceiver) : ISender(szSender), IReceiver(szReceiver) {}
	virtual ~ISendable() {}

	virtual void Print() const override
	{
		ISender::Print();
		IReceiver::Print();
	}

	virtual void Send() const = 0;
};

#endif // ISENDABLE_H
