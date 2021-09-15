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

	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Исходный текст:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer2->Add( m_staticText2, 0, wxALL, 5 );

	m_textSource = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 400,100 ), wxTE_RICH|wxTE_RICH2 );
	fgSizer2->Add( m_textSource, 0, wxALL|wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Ключ"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer4->Add( m_staticText6, 0, wxALL, 5 );

	m_textKey = new wxTextCtrl( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_textKey, 0, wxALL|wxEXPAND, 5 );


	fgSizer2->Add( fgSizer4, 0, 0, 5 );

	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Результат:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizer2->Add( m_staticText8, 0, wxALL, 5 );

	m_textResult = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 400,100 ), wxTE_READONLY|wxTE_RICH|wxTE_RICH2 );
	fgSizer2->Add( m_textResult, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	m_btnEncrypt = new wxButton( this, wxID_ANY, wxT("Шифровать"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_btnEncrypt, 0, wxALL, 5 );

	m_btnDecrypt = new wxButton( this, wxID_ANY, wxT("Расшифровать"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_btnDecrypt, 0, wxALL, 5 );


	fgSizer2->Add( bSizer2, 1, wxEXPAND, 5 );


	this->SetSizer( fgSizer2 );
	this->Layout();
	fgSizer2->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( IMainDialog::OnClose ) );
	m_btnEncrypt->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnEncryptClick ), NULL, this );
	m_btnDecrypt->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnDecryptClick ), NULL, this );
}

IMainDialog::~IMainDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( IMainDialog::OnClose ) );
	m_btnEncrypt->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnEncryptClick ), NULL, this );
	m_btnDecrypt->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnDecryptClick ), NULL, this );

}
