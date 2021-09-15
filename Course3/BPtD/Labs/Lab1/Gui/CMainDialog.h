#ifndef CMAINDIALOG_H
#define CMAINDIALOG_H

#include "GeneratedWindow.h"

class CMainDialog : public IMainDialog
{
public:
	CMainDialog() : IMainDialog(nullptr) {}

private:
	void OnEncryptClick(wxCommandEvent&) override final;
	void OnDecryptClick(wxCommandEvent&) override final;
	void OnClose(wxCloseEvent&) override final;

	void Process(bool decrypt);
};

#endif // CMAINDIALOG_H
