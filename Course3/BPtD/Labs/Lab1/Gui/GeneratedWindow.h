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
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class IMainDialog
///////////////////////////////////////////////////////////////////////////////
class IMainDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText2;
		wxTextCtrl* m_textSource;
		wxStaticText* m_staticText6;
		wxTextCtrl* m_textKey;
		wxStaticText* m_staticText8;
		wxTextCtrl* m_textResult;
		wxButton* m_btnEncrypt;
		wxButton* m_btnDecrypt;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) = 0;
		virtual void OnEncryptClick( wxCommandEvent& event ) = 0;
		virtual void OnDecryptClick( wxCommandEvent& event ) = 0;


	public:

		IMainDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("BPtD Lab 1"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX );
		~IMainDialog();

};

