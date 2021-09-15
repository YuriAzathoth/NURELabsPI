#ifndef INETWORK_H
#define INETWORK_H

#include <cstdint>
#include <functional>
#include <memory>
#include <wx/event.h>
#include <wx/socket.h>
#include <wx/string.h>
#include "Alg/CDiffiHellman.h"

class INetwork : public wxEvtHandler
{
public:
	using FNCallback = std::function<void(const wxString&)>;

	INetwork(FNCallback receive_func);
	virtual ~INetwork();

	void Send(const wxString &message);

protected:
	void BindSocketEvents(wxSocketBase &socket, wxSocketEventFlags flags);

	std::unique_ptr<CDiffiHellman> keycrypt_;

private:
	virtual void OnConnection() = 0;
	virtual void OnDisconnection() {};
	virtual void OnMessageSent(const wxString &message) {};
	virtual void OnMessageReceived(const wxString &message) {};

	void OnSocket(wxSocketEvent &event);

	void Receive(wxSocketBase* socket);
	void ReceiveMsg(wxSocketBase* socket);
	FNCallback receive_func_;

	enum
	{
		SOCKET_ID = 100
	};
	wxDECLARE_EVENT_TABLE();
};

#endif // INETWORK_H
