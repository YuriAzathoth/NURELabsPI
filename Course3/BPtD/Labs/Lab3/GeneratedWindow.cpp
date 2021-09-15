///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GeneratedWindow.h"

///////////////////////////////////////////////////////////////////////////

IMainDialog::IMainDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 3, 1, 0, 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_filePicker = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	fgSizer6->Add( m_filePicker, 0, wxALL|wxEXPAND, 5 );

	m_txtHash = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_txtHash->SetMinSize( wxSize( 320,-1 ) );

	fgSizer6->Add( m_txtHash, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	m_btnCalc = new wxButton( this, wxID_ANY, wxT("&Рассчитать"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_btnCalc, 1, wxALL|wxEXPAND, 5 );

	m_btnBrute = new wxButton( this, wxID_ANY, wxT("&Коллизии"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_btnBrute, 1, wxALL|wxEXPAND, 5 );


	fgSizer6->Add( bSizer2, 1, wxEXPAND, 5 );


	this->SetSizer( fgSizer6 );
	this->Layout();
	fgSizer6->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( IMainDialog::OnClose ) );
	m_btnCalc->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnCalcClick ), NULL, this );
	m_btnBrute->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnBruteClick ), NULL, this );
}

IMainDialog::~IMainDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( IMainDialog::OnClose ) );
	m_btnCalc->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnCalcClick ), NULL, this );
	m_btnBrute->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnBruteClick ), NULL, this );

}
