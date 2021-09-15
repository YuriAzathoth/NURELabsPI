#ifndef CREATEUSERDIALOG_H
#define CREATEUSERDIALOG_H

#include <wx/event.h>
#include "GeneratedWindows.h"
#include "IDatabaseDialog.h"
struct UserData;

class UsersDialog : public IUsersDialog, public IDatabaseDialog
{
	DECLARE_DIALOG(UsersDialog)

public:
	void OnInit(wxInitDialogEvent &event) override final { Update(); }
	void OnClickCreate(wxCommandEvent &event) override final;
	void OnClickEdit(wxCommandEvent &event) override final;
	void OnClickDelete(wxCommandEvent &event) override final;
	void OnSelectName(wxCommandEvent &event) override final;

private:
	void Update();
	void PushData(UserData &rData) const;
	void PullData(const UserData &rData) const;
};

#endif // CREATEUSERDIALOG_H
