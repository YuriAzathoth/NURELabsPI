#include "DatabaseView.h"
#include "UsersDialog.h"

void UsersDialog::OnClickCreate(wxCommandEvent &event)
{
	UserData data;
	PushData(data);
	m_pDbAdapter->InsertUserData(data);
	Update();
}

void UsersDialog::OnClickEdit(wxCommandEvent& event)
{
	UserData data;
	PushData(data);
	m_pDbAdapter->EditUserData(data);
	Update();
}

void UsersDialog::OnClickDelete(wxCommandEvent &event)
{
	m_pDbAdapter->DeleteUserData();
	Update();
}

void UsersDialog::OnSelectName(wxCommandEvent &event)
{
	m_pDbAdapter->SetUserSelection(m_cmbName->GetSelection());
	PullData(m_pDbAdapter->GetUserData());
}

void UsersDialog::Update()
{
	m_pDbAdapter->LoadUsersList(m_cmbName);
}

void UsersDialog::PushData(UserData &rData) const
{
	rData.sName = m_cmbName->GetValue();
	rData.fRange = m_spinRange->GetValue();
}

void UsersDialog::PullData(const UserData &rData) const
{
	m_spinRange->SetValue(rData.fRange);
}
