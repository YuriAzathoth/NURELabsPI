#ifndef CRITERIONSDIALOG_H
#define CRITERIONSDIALOG_H

#include <wx/event.h>
#include "GeneratedWindows.h"
#include "IDatabaseDialog.h"
struct CriterionData;

class CriterionsDialog : public ICriterionsDialog, public IDatabaseDialog
{
	DECLARE_DIALOG(CriterionsDialog)

public:
	void OnInit(wxInitDialogEvent &event) override final { Update(); }
	void OnClickCreate(wxCommandEvent &event) override final;
	void OnClickEdit(wxCommandEvent &event) override final;
	void OnClickDelete(wxCommandEvent &event) override final;
	void OnSelectName(wxCommandEvent &event) override final;

private:
	void Update();
	void PushData(CriterionData &rData) const;
	void PullData(const CriterionData &rData) const;
};

#endif // CRITERIONSDIALOG_H
