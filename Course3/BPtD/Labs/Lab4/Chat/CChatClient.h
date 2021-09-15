#ifndef CCHATCLIENT_H
#define CCHATCLIENT_H

#include "INetwork.h"

class CChatClient : public INetwork
{
public:
	CChatClient(const wxString &address, uint16_t port, FNCallback receive_func);

private:
	void OnConnection() override final;
	void OnMessageSent(const wxString &message) override final;

	void ReceiveKeys();

	wxSocketClient client_;
	uint8_t id_;
};

#endif // CCHATCLIENT_H
