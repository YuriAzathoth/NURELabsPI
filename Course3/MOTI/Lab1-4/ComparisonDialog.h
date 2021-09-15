#ifndef COMPARISONDIALOG_H
#define COMPARISONDIALOG_H

#include <vector>
#include <wx/event.h>
#include "DatabaseData.h"
#include "GeneratedWindows.h"
#include "IDatabaseDialog.h"

class ComparisonDialog : public IComparisonDialog, public IDatabaseDialog
{
	DECLARE_DIALOG(ComparisonDialog)

public:
	void OnInit(wxInitDialogEvent &event) override final;
	void OnSelect1Click(wxCommandEvent &event) override final;
	void OnSelect2Click(wxCommandEvent &event) override final;

private:
	void UpdateGrid();
	void WriteResults();

	using TAlternativeData	= DatabaseData<AlternativeData>;
	using TCriterionData	= DatabaseData<CriterionData>;
	std::vector<unsigned>	m_nAltIds;
	std::vector<unsigned>	m_nCritIds;
    std::vector<unsigned>::const_iterator m_itVariants[2];
    std::vector<unsigned>::const_iterator m_itNext;
    std::vector<unsigned>::const_iterator m_itBest;
    const TAlternativeData*	m_pAlternatives;
    const TCriterionData*	m_pCriterions;
};

#endif // COMPARISONDIALOG_H
