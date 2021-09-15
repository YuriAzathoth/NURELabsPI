#include <fstream>
#include <stdexcept>
#include "CChatClient.h"
#include "CChatMessage.h"

CChatClient::CChatClient(const wxString &address, uint16_t port, FNCallback receive_func) :
	INetwork(receive_func)
{
	wxIPV4address ip;
	ip.Hostname(address);
	ip.Service(port);

	client_.Connect(ip, false);
	if (!client_.IsOk())
		throw std::runtime_error("Client error: Port is busy");

	BindSocketEvents(client_, wxSOCKET_CONNECTION_FLAG | wxSOCKET_INPUT_FLAG | wxSOCKET_LOST_FLAG);
}

void CChatClient::OnConnection()
{
	ReceiveKeys();
}

void CChatClient::OnMessageSent(const wxString &message)
{
	std::string buffer = message.ToStdString();
	keycrypt_->Process(buffer, 0);

	CChatMessage msg(id_, buffer);
	msg.Write(&client_);
}

void CChatClient::ReceiveKeys()
{
	CDiffiHellman::TNumber q;
	CDiffiHellman::TNumber a;
	CDiffiHellman::TNumber y;

	client_.Read(&id_, sizeof(id_));
	client_.Read(&q, sizeof(q));
	client_.Read(&a, sizeof(a));
	client_.Read(&y, sizeof(y));

	keycrypt_ = std::make_unique<CDiffiHellman>(q, a, y);

	y = keycrypt_->GetPublicKey();
	client_.Write(&y, sizeof(y));

	std::ofstream file(std::string("client") + std::to_string(id_) + ".txt");
	file << *keycrypt_.get();
}
