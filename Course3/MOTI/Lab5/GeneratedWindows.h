///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/font.h>
#include <wx/grid.h>
#include <wx/gdicmn.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class IMainWindow
///////////////////////////////////////////////////////////////////////////////
class IMainWindow : public wxDialog
{
	private:

	protected:
		wxGrid* m_gridMatrix;
		wxStaticText* m_staticText2;
		wxStaticText* m_txtScorePlayer;
		wxStaticText* m_staticText6;
		wxStaticText* m_txtScoreBot;
		wxStaticText* m_staticText12;
		wxStaticText* m_txtBotSelection;
		wxStaticText* m_txtStatus;
		wxButton* m_btnStone;
		wxButton* m_btnScissors;
		wxButton* m_btnPaper;
		wxButton* m_btnHelp;
		wxButton* m_btnRestart;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnInit( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void OnEditMatrix( wxGridEvent& event ) { event.Skip(); }
		virtual void OnClickStone( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickScissors( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickPaper( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickHelp( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickReset( wxCommandEvent& event ) { event.Skip(); }


	public:

		IMainWindow( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("МОТИ Лаб5"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~IMainWindow();

};

