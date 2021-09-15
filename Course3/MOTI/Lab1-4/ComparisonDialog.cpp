#include <algorithm>
#include "ComparisonDialog.h"
#include "DatabaseView.h"

void ComparisonDialog::OnInit(wxInitDialogEvent &event)
{
	m_pAlternatives	= m_pDbAdapter->GetAlternatives();
	m_pCriterions	= m_pDbAdapter->GetCriterions();

	m_nAltIds.resize(m_pAlternatives->Data.size());
	std::transform(m_pAlternatives->Data.begin(), m_pAlternatives->Data.end(), m_nAltIds.begin(), [](const auto &pair) -> float
	{
        return pair.second.nId;
	});
	m_nCritIds.resize(m_pCriterions->Data.size());
	std::transform(m_pCriterions->Data.begin(), m_pCriterions->Data.end(), m_nCritIds.begin(), [](const auto &pair) -> float
	{
        return pair.second.nId;
	});

	m_itNext		= m_nAltIds.cbegin();
	m_itVariants[0]	= m_itNext;
	m_itVariants[1]	= ++m_itNext;

	m_gridPair->AppendRows(m_pCriterions->Data.size());
	UpdateGrid();
}

void ComparisonDialog::OnSelect1Click(wxCommandEvent &event)
{
	m_itBest = m_itVariants[0];
	if (++m_itNext == m_nAltIds.cend())
	{
		WriteResults();
		return;
	}
	m_itVariants[1] = m_itNext;
	UpdateGrid();
}

void ComparisonDialog::OnSelect2Click(wxCommandEvent &event)
{
	m_itBest = m_itVariants[1];
	if (++m_itNext == m_nAltIds.cend())
	{
		WriteResults();
		return;
	}
	m_itVariants[0] = m_itNext;
	UpdateGrid();
}

void ComparisonDialog::UpdateGrid()
{
	for (int i = 0; i < static_cast<int>(m_pCriterions->Data.size()); ++i)
		m_gridPair->SetRowLabelValue(i, m_pCriterions->Data.at(m_nCritIds.at(i)).sName);
	for (int i = 0; i < 2; ++i)
	{
		const AlternativeData &alternative = m_pAlternatives->Data.at(*m_itVariants[i]);
		m_gridPair->SetColLabelValue(i, alternative.sName);
		for (int j = 0; j < static_cast<int>(m_pCriterions->Data.size()); ++j)
			m_gridPair->SetCellValue(j, i, wxString::Format("%f", alternative.Marks.at(m_nCritIds.at(j)).fNumMark));
	}
	m_gridPair->AutoSize();
	Fit();
}

void ComparisonDialog::WriteResults()
{
	m_pDbAdapter->InsertResult(*m_itBest);
	EndModal(0);
}
