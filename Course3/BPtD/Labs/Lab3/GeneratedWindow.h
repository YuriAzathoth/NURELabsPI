///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/filepicker.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class IMainDialog
///////////////////////////////////////////////////////////////////////////////
class IMainDialog : public wxDialog
{
	private:

	protected:
		wxFilePickerCtrl* m_filePicker;
		wxTextCtrl* m_txtHash;
		wxButton* m_btnCalc;
		wxButton* m_btnBrute;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) = 0;
		virtual void OnCalcClick( wxCommandEvent& event ) = 0;
		virtual void OnBruteClick( wxCommandEvent& event ) = 0;


	public:

		IMainDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("BPtD Lab 1"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX );
		~IMainDialog();

};

