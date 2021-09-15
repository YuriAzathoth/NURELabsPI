#include "AlternativesDialog.h"
#include "DatabaseView.h"

void AlternativesDialog::OnInit(wxInitDialogEvent& event)
{
	m_pDbAdapter->LoadMarksGrid(m_gridMarks, m_CritIdToPos);
	Update();
	Fit();
}

void AlternativesDialog::OnClickCreate(wxCommandEvent &event)
{
	AlternativeData data;
	PushData(data);
	m_pDbAdapter->InsertAlternativeData(data);
	Update();
}

void AlternativesDialog::OnClickEdit(wxCommandEvent &event)
{
	AlternativeData data;
	PushData(data);
	m_pDbAdapter->EditAlternativeData(data);
	m_pDbAdapter->UpdateMarksData(data);
	Update();
}

void AlternativesDialog::OnClickDelete(wxCommandEvent &event)
{
	m_pDbAdapter->DeleteAlternativeData();
	Update();
}

void AlternativesDialog::OnSelectName(wxCommandEvent &event)
{
	m_pDbAdapter->SetAlternativeSelection(m_cmbName->GetSelection());
	PullData(m_pDbAdapter->GetAlternativeData());
}

void AlternativesDialog::Update()
{
	m_pDbAdapter->LoadAlternativesList(m_cmbName);
	PullData(m_pDbAdapter->GetAlternativeData());
}

void AlternativesDialog::PushData(AlternativeData &rData) const
{
	rData.sName = m_cmbName->GetValue();

	const DatabaseData<CriterionData>* crit_data = m_pDbAdapter->GetCriterions();
	std::for_each(crit_data->Data.begin(), crit_data->Data.end(), [this, &rData](const auto &crit)
	{
		const unsigned nPos = m_CritIdToPos.at(crit.first);
		MarkData &data	= rData.Marks[crit.first];
        data.sName		= m_gridMarks->GetCellValue(nPos, 1);
        data.nRange		= wxAtoi(m_gridMarks->GetCellValue(nPos, 2));
        data.fNumMark	= wxAtof(m_gridMarks->GetCellValue(nPos, 3));
        data.fNormMark	= wxAtof(m_gridMarks->GetCellValue(nPos, 4));
        data.nCritId	= crit.first;
	});
}

void AlternativesDialog::PullData(const AlternativeData &rData) const
{
	m_cmbName->SetValue(rData.sName);

	const DatabaseData<CriterionData>* crit_data = m_pDbAdapter->GetCriterions();
	std::for_each(crit_data->Data.begin(), crit_data->Data.end(), [this, rData](const auto &crit)
	{
		const unsigned nPos = m_CritIdToPos.at(crit.first);
		auto itMark = rData.Marks.find(crit.first);
		if (itMark != rData.Marks.end())
		{
			m_gridMarks->SetCellValue(nPos, 1, itMark->second.sName);
			m_gridMarks->SetCellValue(nPos, 2, wxString::Format("%u", itMark->second.nRange));
			m_gridMarks->SetCellValue(nPos, 3, wxString::Format("%f", itMark->second.fNumMark));
			m_gridMarks->SetCellValue(nPos, 4, wxString::Format("%f", itMark->second.fNormMark));
		}
		else
		{
			m_pDbAdapter->InsertMarkData(crit.first);
			m_gridMarks->SetCellValue(nPos, 1, "");
			m_gridMarks->SetCellValue(nPos, 2, "0");
			m_gridMarks->SetCellValue(nPos, 3, "0");
			m_gridMarks->SetCellValue(nPos, 4, "0");
		}
	});
}
