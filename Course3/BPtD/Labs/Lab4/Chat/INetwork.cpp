#include <wx/log.h>
#include "CChatMessage.h"
#include "INetwork.h"

wxBEGIN_EVENT_TABLE(INetwork, wxEvtHandler)
	EVT_SOCKET(SOCKET_ID, INetwork::OnSocket)
wxEND_EVENT_TABLE()

INetwork::INetwork(FNCallback receive_func) :
	receive_func_(receive_func)
{
}

INetwork::~INetwork()
{
}

void INetwork::OnSocket(wxSocketEvent &event)
{
	switch (event.GetSocketEvent())
	{
	case wxSOCKET_INPUT:
		Receive(event.GetSocket());
		break;
	case wxSOCKET_CONNECTION:
		OnConnection();
		break;
	case wxSOCKET_LOST:
		OnDisconnection();
		break;
	}
}

void INetwork::Send(const wxString &message)
{
	OnMessageSent(message);
}

void INetwork::Receive(wxSocketBase* socket)
{
	CChatMessage msg;
	msg.Read(socket);

	std::string message = msg.GetMessage().ToStdString();
	keycrypt_->Process(message, msg.GetId());

	OnMessageReceived(message);
	receive_func_(message);
}

void INetwork::BindSocketEvents(wxSocketBase &socket, wxSocketEventFlags flags)
{
	socket.SetEventHandler(*this, SOCKET_ID);
	socket.SetNotify(flags);
	socket.Notify(true);
}
