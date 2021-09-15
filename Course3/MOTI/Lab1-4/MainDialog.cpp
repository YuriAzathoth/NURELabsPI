#include "AlternativesDialog.h"
#include "ComparisonDialog.h"
#include "CriterionsDialog.h"
#include "DatabaseView.h"
#include "MainDialog.h"
#include "UsersDialog.h"

void MainDialog::OnClickEditUsers(wxCommandEvent &event)
{
	wxDialog* pDialog = new UsersDialog(this, m_pDbAdapter);
	pDialog->ShowModal();
	Update();
}

void MainDialog::OnClickEditAlternatives(wxCommandEvent &sevent)
{
	wxDialog* pDialog = new AlternativesDialog(this, m_pDbAdapter);
	pDialog->ShowModal();
	Update();
}

void MainDialog::OnClickEditCriterions(wxCommandEvent &event)
{
	wxDialog* pDialog = new CriterionsDialog(this, m_pDbAdapter);
	pDialog->ShowModal();
	Update();
}

void MainDialog::OnSelectName(wxCommandEvent& event)
{
	m_pDbAdapter->SetUserSelection(m_selUserName->GetSelection());
	UpdateData();
}

void MainDialog::OnClickCalcLab2(wxCommandEvent &event)
{
	m_pDbAdapter->CalculateLab2(m_spinThreshold->GetValue());
	UpdateData();
}

void MainDialog::OnClickCalcLab3(wxCommandEvent &event)
{
	wxDialog* pDialog = new ComparisonDialog(this, m_pDbAdapter);
	pDialog->ShowModal();
	UpdateData();
}

void MainDialog::OnClickCalcLab4(wxCommandEvent &event)
{
	m_pDbAdapter->CalculateLab4(m_spinThreshold->GetValue());
	UpdateData();
}

void MainDialog::OnSaveWeights(wxCommandEvent& event)
{
	m_pDbAdapter->PushWeights(m_gridVitality);
	UpdateData();
}

void MainDialog::Update()
{
	m_pDbAdapter->LoadUsersList(m_selUserName);
	UpdateData();
}

void MainDialog::UpdateData()
{
	m_pDbAdapter->PullWeights(m_gridVitality);
	m_pDbAdapter->LoadResultsGrid(m_gridResult);
	Fit();
}
