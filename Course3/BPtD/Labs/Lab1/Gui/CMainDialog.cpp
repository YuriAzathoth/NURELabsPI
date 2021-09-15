#include <cstring>
#include <wx/app.h>
#include <wx/msgdlg.h>
#include "des.h"
#include "CMainDialog.h"

using namespace std;

void CMainDialog::OnEncryptClick(wxCommandEvent&)
{
	Process(true);
}

void CMainDialog::OnDecryptClick(wxCommandEvent&)
{
	Process(false);
}

void CMainDialog::OnClose(wxCloseEvent&)
{
	wxExit();
}

void CMainDialog::Process(bool decrypt)
{
	const uint64_t key = atoll(m_textKey->GetValue().ToStdString().c_str());
	if (!des_check_key(key))
	{
		wxMessageBox(wxT("Слабый ключ! Используйте другой ключ!"), wxT("Ошибка проверки ключа"), wxCENTER | wxICON_ERROR);
		return;
	}

	const wxString source = m_textSource->GetValue();
	const size_t length = source.size() + 1;
	char* buffer = new char[length];
	strcpy_s(buffer, length, source);

	des_process(buffer, length, key, decrypt);
	m_textResult->SetValue(buffer);

	delete[] buffer;
}
