#ifndef CMAINDIALOG_H
#define CMAINDIALOG_H

#include <thread>
#include "CCryptor.h"
#include "CServer.h"
#include "GeneratedWindow.h"

class CMainDialog : public IMainDialog
{
public:
	CMainDialog();

private:
	void OnInit(wxInitDialogEvent&) override final;
	void OnClose(wxCloseEvent&) override final;
	void OnServerReceived(const char* received_data);

	void SendPublicKey();
	void DecryptForm(const char* received_data);

	CCryptor cryptor_;
	boost::asio::io_context io_context_;
	CServer server_;
	std::thread server_thread_;
};

#endif // CMAINDIALOG_H
