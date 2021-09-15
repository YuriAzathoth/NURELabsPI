#include <clocale>
#include <wx/app.h>
#include "CMainDialog.h"

class CMainApplication : public wxApp
{
	bool OnInit() override final
	{
        setlocale(LC_ALL, "");
        wxDialog* dlgMain = new CMainDialog();
        dlgMain->ShowModal();
        SetTopWindow(dlgMain);
        return true;
	}
};

IMPLEMENT_APP(CMainApplication)
