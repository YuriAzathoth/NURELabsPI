#include <memory>
#include <wx/app.h>
#include <wx/msgdlg.h>
#include "MainDialog.h"
#include "DatabaseView.h"

class MainApplication : public wxApp
{
public:
	bool OnInit() override final
	{
		try
		{
			m_pDbAdapter = std::make_shared<DatabaseView>();
			wxInitAllImageHandlers();
			wxDialog* pMainDialog = new MainDialog(nullptr, m_pDbAdapter);
			pMainDialog->ShowModal();
			SetTopWindow(pMainDialog);
		}
		catch(std::exception &e)
		{
			wxMessageBox(wxString::FromUTF8(e.what()), wxT("Неожиданное исключение!"));
			wxExit();
		}
		return true;
	}

private:
	std::shared_ptr<DatabaseView> m_pDbAdapter;
};

IMPLEMENT_APP_CONSOLE(MainApplication)
