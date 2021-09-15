#ifndef CMAINDIALOG_H
#define CMAINDIALOG_H

#include <vector>
#include "GeneratedWindow.h"

class CMainDialog : public IMainDialog
{
public:
	CMainDialog() : IMainDialog(nullptr) {}

private:
	void OnCalcClick(wxCommandEvent&);
	void OnBruteClick(wxCommandEvent&);
	void OnClose(wxCloseEvent&) { wxExit(); }

	static void ReadWholeFile(const char* filename, std::vector<char> &data);
	static void WriteWholeFile(const char* filename, const std::vector<char> &data);
};

#endif // CMAINDIALOG_H
