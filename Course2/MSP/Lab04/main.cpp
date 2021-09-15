#include <iostream>
#include "CMessage.h"
using namespace std;

int main()
{
	IPrintable* pTest = new CMessage("John Smith", "Alex Johnson", "Just testing message, nothing more!");
	pTest->Print();
	dynamic_cast<ISendable*>(pTest)->Send();
	delete pTest;
    return 0;
}
