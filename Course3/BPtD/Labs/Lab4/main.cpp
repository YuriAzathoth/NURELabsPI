#include <clocale>
#include <wx/app.h>
#include "GUI/CMainDialog.h"

class CMainApplication : public wxApp
{
private:
	bool OnInit() override final
	{
        setlocale(LC_ALL, "");

        CMainDialog* dlgMain = new CMainDialog();
        dlgMain->Show();
        SetTopWindow(dlgMain);

        return true;
	}

};

IMPLEMENT_APP(CMainApplication)
