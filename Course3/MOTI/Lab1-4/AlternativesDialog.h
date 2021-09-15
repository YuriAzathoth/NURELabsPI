#ifndef ALTERNATIVESDIALOG_H
#define ALTERNATIVESDIALOG_H

#include <unordered_map>
#include <wx/event.h>
#include "GeneratedWindows.h"
#include "IDatabaseDialog.h"
namespace nanodbc { class connection; }
class AlternativeData;
class VectorData;

class AlternativesDialog : public IAlternativesDialog, public IDatabaseDialog
{
	DECLARE_DIALOG(AlternativesDialog)

public:
	void OnInit(wxInitDialogEvent &event) override final;
	void OnClickCreate(wxCommandEvent &event) override final;
	void OnClickEdit(wxCommandEvent &event) override final;
	void OnClickDelete(wxCommandEvent &event) override final;
	void OnSelectName(wxCommandEvent &event) override final;

private:
	void Update();
	void PushData(AlternativeData &rAltData) const;
	void PullData(const AlternativeData &rAltData) const;

	std::unordered_map<unsigned, unsigned> m_CritIdToPos;
};

#endif // ALTERNATIVESDIALOG_H
