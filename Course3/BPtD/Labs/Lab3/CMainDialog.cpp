#include <algorithm>
#include <fstream>
#include <streambuf>
#include <wx/app.h>
#include <wx/msgdlg.h>
#include "CMainDialog.h"
#include "hash.h"

void CMainDialog::OnCalcClick(wxCommandEvent&)
{
	const wxString filename = m_filePicker->GetPath();
	if (filename.empty())
	{
		wxLogError(wxT("File is not selected!"));
		return;
	}

	std::vector<char> data;
	ReadWholeFile(filename.c_str().AsChar(), data);
	uint8_t hash = hash_text(data.data(), data.size());
	m_txtHash->SetValue(wxString::Format("%d", hash));
}

void CMainDialog::OnBruteClick(wxCommandEvent&)
{
	const wxString filename = m_filePicker->GetPath();
	if (filename.empty())
	{
		wxLogError(wxT("File is not selected!"));
		return;
	}

	std::vector<char> original;
	std::vector<char> candidate;

	ReadWholeFile(filename.c_str().AsChar(), original);
	candidate.assign(original.begin(), original.end());

	uint8_t hash = hash_text(original.data(), original.size());
	int pos = hash_brute(candidate.data(), original.data(), original.size(), hash);
	if (pos != -1)
	{
		wxFileDialog save_file_dlg(this, wxT("Save file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
		if (save_file_dlg.ShowModal() != wxID_CANCEL)
			WriteWholeFile(save_file_dlg.GetPath().c_str().AsChar(), candidate);
	}
	else
		wxLogError(wxT("Collisions is not found!"));
}

void CMainDialog::ReadWholeFile(const char* filename, std::vector<char> &data)
{
	std::ifstream file(filename, std::ios::binary);
	data.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();
}

void CMainDialog::WriteWholeFile(const char* filename, const std::vector<char> &data)
{
	std::ofstream file(filename, std::ios::binary);
	file.write(data.data(), data.size());
	file.close();
}
