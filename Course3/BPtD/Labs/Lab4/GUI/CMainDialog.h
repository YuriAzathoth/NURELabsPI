#ifndef CMAINDIALOG_H
#define CMAINDIALOG_H

#include <cstdint>
#include <string>
#include <unordered_set>
#include <wx/event.h>
#include <wx/ptr_shrd.h>
#include <wx/socket.h>
#include "Chat/INetwork.h"
#include "GeneratedWindow.h"

class CMainDialog : public IMainDialog
{
public:
	CMainDialog();

private:
	void OnItemCreate	(wxCommandEvent &event) override final;
	void OnItemConnect	(wxCommandEvent &event) override final;
	void OnItemDisonnect(wxCommandEvent &event) override final;
	void OnItemExit		(wxCommandEvent &event) override final;
	void OnSendMessage	(wxCommandEvent &event) override final;

	void OnReceive		(const wxString &message);

	wxSharedPtr<INetwork> network_;

	wxDECLARE_EVENT_TABLE();
};

#endif // CMAINDIALOG_H
