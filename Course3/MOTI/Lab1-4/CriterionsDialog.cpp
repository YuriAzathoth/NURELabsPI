#include "CriterionsDialog.h"
#include "DatabaseView.h"

void CriterionsDialog::OnClickCreate(wxCommandEvent &event)
{
	CriterionData data;
	PushData(data);
	m_pDbAdapter->InsertCriterionData(data);
	Update();
}

void CriterionsDialog::OnClickEdit(wxCommandEvent &event)
{
	CriterionData data;
	PushData(data);
	m_pDbAdapter->EditCriterionData(data);
	Update();
}

void CriterionsDialog::OnClickDelete(wxCommandEvent &event)
{
	m_pDbAdapter->DeleteCriterionData();
	Update();
}

void CriterionsDialog::OnSelectName(wxCommandEvent &event)
{
	m_pDbAdapter->SetCriterionSelection(m_cmbName->GetSelection());
	PullData(m_pDbAdapter->GetCriterionData());
}

void CriterionsDialog::Update()
{
	m_pDbAdapter->LoadCriterionsList(m_cmbName);
}

void CriterionsDialog::PushData(CriterionData &rData) const
{
	rData.sName = m_cmbName->GetValue();
	rData.nRange = m_spinRange->GetValue();
	rData.nWeight = m_spinWeight->GetValue();
	rData.nType = m_selType->GetSelection();
	rData.nOptimal = m_selOptimal->GetSelection();
	rData.sUnits = m_cmbUnits->GetValue();
	rData.sScale = m_cmbScaleType->GetValue();
}

void CriterionsDialog::PullData(const CriterionData &rData) const
{
	m_spinRange->SetValue(rData.nRange);
	m_spinWeight->SetValue(rData.nWeight);
	m_selType->SetSelection(rData.nType);
	m_selOptimal->SetSelection(rData.nOptimal);
	m_cmbUnits->SetValue(rData.sUnits);
	m_cmbScaleType->SetValue(rData.sScale);
}
