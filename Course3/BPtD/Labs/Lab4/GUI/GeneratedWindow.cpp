///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GeneratedWindow.h"

///////////////////////////////////////////////////////////////////////////

IMainDialog::IMainDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );

	wxMenuBar* m_menubar2;
	m_menubar2 = new wxMenuBar( 0 );
	wxMenu* m_menu2;
	m_menu2 = new wxMenu();
	m_menuItemCreate = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("&Создать") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItemCreate );

	m_menuItemConnect = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("&Подключиться") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItemConnect );

	m_menuItemDisconnect = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("&Отключиться") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItemDisconnect );
	m_menuItemDisconnect->Enable( false );

	m_menu2->AppendSeparator();

	wxMenuItem* m_menuItemExit;
	m_menuItemExit = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("&Выход") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItemExit );

	m_menubar2->Append( m_menu2, wxT("&Чат") );

	this->SetMenuBar( m_menubar2 );

	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer6->AddGrowableCol( 0 );
	fgSizer6->AddGrowableRow( 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	fgSizer6->SetMinSize( wxSize( 400,300 ) );
	m_txtChat = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_MULTILINE|wxTE_READONLY );
	fgSizer6->Add( m_txtChat, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	m_txtMessage = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_txtMessage, 1, wxALL|wxEXPAND, 5 );

	m_btnSend = new wxButton( this, wxID_ANY, wxT("&Отправить"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_btnSend, 0, wxALL, 5 );


	fgSizer6->Add( bSizer4, 1, wxEXPAND, 5 );


	this->SetSizer( fgSizer6 );
	this->Layout();
	fgSizer6->Fit( this );
	m_statusBar = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	m_menu2->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( IMainDialog::OnItemCreate ), this, m_menuItemCreate->GetId());
	m_menu2->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( IMainDialog::OnItemConnect ), this, m_menuItemConnect->GetId());
	m_menu2->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( IMainDialog::OnItemDisonnect ), this, m_menuItemDisconnect->GetId());
	m_menu2->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( IMainDialog::OnItemExit ), this, m_menuItemExit->GetId());
	m_btnSend->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnSendMessage ), NULL, this );
}

IMainDialog::~IMainDialog()
{
	// Disconnect Events
	m_btnSend->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnSendMessage ), NULL, this );

}
