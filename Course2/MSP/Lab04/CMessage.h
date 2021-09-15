#ifndef CMESSAGE_H
#define CMESSAGE_H

#include <cstring>
#include <iostream>
#include "ISendable.h"
using namespace std;

class CMessage : public ISendable
{
public:
	CMessage(const char* szSender,
			const char* szReceiver,
			const char* szMessage) :
		ISendable(szSender, szReceiver),
		m_szMessage(strdup(szMessage))
	{}
	~CMessage() { free(m_szMessage); }

	void Print() const override final
	{
        ISendable::Print();
        cout << "Message:\t" << m_szMessage << endl;
	}

	void Send() const override final
	{
		cout << "Message has successfully sended!" << endl;
	}

private:
	char* m_szMessage;
};

#endif // CMESSAGE_H
