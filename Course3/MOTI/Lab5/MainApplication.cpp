#include <wx/app.h>
#include "MainWindow.h"

class MainApplication : public wxApp
{
public:
	bool OnInit() override final
	{
		wxInitAllImageHandlers();
		wxDialog* pMainDialog = new MainWindow(nullptr);
		pMainDialog->ShowModal();
		SetTopWindow(pMainDialog);
		return true;
	}
};

IMPLEMENT_APP(MainApplication)
