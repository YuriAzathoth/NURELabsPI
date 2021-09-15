#include <fstream>
#include <stdexcept>
#include "CChatMessage.h"
#include "CChatServer.h"

CChatServer::CChatServer(uint16_t port, FNCallback receive_func) :
	INetwork(receive_func),
	last_id_(1)
{
	keycrypt_ = std::make_unique<CDiffiHellman>();

	wxIPV4address ip;
	ip.Service(port);
	server_ = std::make_unique<wxSocketServer>(ip);
	if (!server_->IsOk())
		throw std::runtime_error("Server error: Port is busy");

	BindSocketEvents(*server_, wxSOCKET_CONNECTION_FLAG | wxSOCKET_LOST_FLAG);
}

void CChatServer::OnMessageSent(const wxString &message)
{
	for (auto &client_socket : clients_)
	{
		std::string buffer = message.ToStdString();
		keycrypt_->Process(buffer, client_socket.first);

		CChatMessage msg(id_, buffer.c_str());
		msg.Write(client_socket.second.get());
	}
}

void CChatServer::OnMessageReceived(const wxString &message)
{
	Send(message);
}

void CChatServer::OnConnection()
{
	wxSocketBase* client_socket = server_->Accept(false);
	if (!client_socket)
		return;

	const uint8_t client_id = last_id_++;

	clients_.emplace(client_id, client_socket);
	BindSocketEvents(*client_socket, wxSOCKET_INPUT_FLAG);

	SendKeys(client_socket, client_id);
}

void CChatServer::OnDisconnection()
{
}

void CChatServer::SendKeys(wxSocketBase* client, uint8_t client_id)
{
	CDiffiHellman::TNumber q = keycrypt_->GetQ();
	CDiffiHellman::TNumber a = keycrypt_->GetA();
	CDiffiHellman::TNumber y = keycrypt_->GetPublicKey();

	client->Write(&client_id, sizeof(client_id));
	client->Write(&q, sizeof(q));
	client->Write(&a, sizeof(a));
	client->Write(&y, sizeof(y));

	client->Read(&y, sizeof(y));
	keycrypt_->CreateKey(y, client_id);

	std::ofstream file("server.txt");
	file << *keycrypt_.get();
}
