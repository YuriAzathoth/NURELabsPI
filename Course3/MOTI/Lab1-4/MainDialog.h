#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <wx/app.h>
#include <wx/event.h>
#include "GeneratedWindows.h"
#include "IDatabaseDialog.h"

class MainDialog : public IMainDialog, public IDatabaseDialog
{
	DECLARE_DIALOG(MainDialog)

public:
	void OnInit(wxInitDialogEvent &event) override final { Update(); }
	void OnClose(wxCloseEvent &event) override final { wxExit(); }
	void OnClickEditUsers(wxCommandEvent &event) override final;
	void OnClickEditAlternatives(wxCommandEvent &event) override final;
	void OnClickEditCriterions(wxCommandEvent &event) override final;
	void OnSelectName(wxCommandEvent &event) override final;
	void OnClickCalcLab2(wxCommandEvent &event) override final;
	void OnClickCalcLab3(wxCommandEvent &event) override final;
	void OnClickCalcLab4(wxCommandEvent &event) override final;
	void OnSaveWeights(wxCommandEvent &event) override final;

private:
	void Update();
	void UpdateData();
};

#endif // MAINDIALOG_H
