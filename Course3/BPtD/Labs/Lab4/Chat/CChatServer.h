#ifndef CCHATSERVER_H
#define CCHATSERVER_H

#include <memory>
#include <unordered_map>
#include "INetwork.h"

class CChatServer : public INetwork
{
public:
	CChatServer(uint16_t port, FNCallback receive_func);

private:
	void OnConnection() override final;
	void OnDisconnection() override final;
	void OnMessageSent(const wxString &message) override final;
	void OnMessageReceived(const wxString &message) override final;

	void SendKeys(wxSocketBase* client, uint8_t client_id);

	std::unordered_map<uint8_t, std::shared_ptr<wxSocketBase>> clients_;
	std::unique_ptr<wxSocketServer> server_;
	uint8_t last_id_;

	static const uint8_t id_ = 0;
};

#endif // CCHATSERVER_H
