#include <wx/app.h>
#include "Chat/CChatClient.h"
#include "Chat/CChatServer.h"
#include "CMainDialog.h"

#define HOST_PORT 12345
#define STATUS_OFFLINE wxT("Оффлайн")
#define STATUS_CLIENT wxT("Клиент")
#define STATUS_SERVER wxT("Сервер")

wxBEGIN_EVENT_TABLE(CMainDialog, IMainDialog)
//	EVT_SOCKET(SOCKET_ID, INetwork::OnSocket)
wxEND_EVENT_TABLE()

CMainDialog::CMainDialog() : IMainDialog(nullptr)
{
	m_statusBar->SetStatusText(STATUS_OFFLINE);
}

void CMainDialog::OnItemCreate(wxCommandEvent &event)
{
	network_ = new CChatServer(HOST_PORT, std::bind(&CMainDialog::OnReceive, this, std::placeholders::_1));

	m_menuItemCreate->Enable(false);
	m_menuItemConnect->Enable(false);
	m_menuItemDisconnect->Enable(true);
	m_statusBar->SetStatusText(STATUS_SERVER);
}

void CMainDialog::OnItemConnect(wxCommandEvent &event)
{
	network_ = new CChatClient("localhost", HOST_PORT, std::bind(&CMainDialog::OnReceive, this, std::placeholders::_1));

	m_menuItemCreate->Enable(false);
	m_menuItemConnect->Enable(false);
	m_menuItemDisconnect->Enable(true);
	m_statusBar->SetStatusText(STATUS_CLIENT);
}

void CMainDialog::OnItemDisonnect(wxCommandEvent &event)
{
	network_ = nullptr;

	m_menuItemCreate->Enable(true);
	m_menuItemConnect->Enable(true);
	m_menuItemDisconnect->Enable(false);
	m_statusBar->SetStatusText(STATUS_OFFLINE);
}

void CMainDialog::OnItemExit(wxCommandEvent &event)
{
	wxExit();
}

void CMainDialog::OnSendMessage(wxCommandEvent &event)
{
	const wxString message = m_txtMessage->GetValue();
	network_->Send(message);
	m_txtChat->AppendText(wxString("\n") + message);
	m_txtMessage->SetValue("");
}

void CMainDialog::OnReceive(const wxString &message)
{
	m_txtChat->AppendText(wxString("\n") + message);
}
