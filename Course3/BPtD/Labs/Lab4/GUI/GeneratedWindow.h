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
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class IMainDialog
///////////////////////////////////////////////////////////////////////////////
class IMainDialog : public wxFrame
{
	private:

	protected:
		wxMenuItem* m_menuItemCreate;
		wxMenuItem* m_menuItemConnect;
		wxMenuItem* m_menuItemDisconnect;
		wxTextCtrl* m_txtChat;
		wxTextCtrl* m_txtMessage;
		wxButton* m_btnSend;
		wxStatusBar* m_statusBar;

		// Virtual event handlers, overide them in your derived class
		virtual void OnItemCreate( wxCommandEvent& event ) = 0;
		virtual void OnItemConnect( wxCommandEvent& event ) = 0;
		virtual void OnItemDisonnect( wxCommandEvent& event ) = 0;
		virtual void OnItemExit( wxCommandEvent& event ) = 0;
		virtual void OnSendMessage( wxCommandEvent& event ) = 0;


	public:

		IMainDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("BPtD Lab 4"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~IMainDialog();

};

