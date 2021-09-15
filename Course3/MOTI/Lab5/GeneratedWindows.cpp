///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GeneratedWindows.h"

///////////////////////////////////////////////////////////////////////////

IMainWindow::IMainWindow( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_gridMatrix = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_gridMatrix->CreateGrid( 4, 4 );
	m_gridMatrix->EnableEditing( true );
	m_gridMatrix->EnableGridLines( true );
	m_gridMatrix->EnableDragGridSize( false );
	m_gridMatrix->SetMargins( 0, 0 );

	// Columns
	m_gridMatrix->EnableDragColMove( false );
	m_gridMatrix->EnableDragColSize( true );
	m_gridMatrix->SetColLabelSize( 30 );
	m_gridMatrix->SetColLabelValue( 0, wxT("Камень") );
	m_gridMatrix->SetColLabelValue( 1, wxT("Ножницы") );
	m_gridMatrix->SetColLabelValue( 2, wxT("Бумага") );
	m_gridMatrix->SetColLabelValue( 3, wxT("Сумма") );
	m_gridMatrix->SetColLabelValue( 4, wxT("Минимум") );
	m_gridMatrix->SetColLabelValue( 5, wxT("Сумма") );
	m_gridMatrix->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_gridMatrix->EnableDragRowSize( true );
	m_gridMatrix->SetRowLabelSize( 80 );
	m_gridMatrix->SetRowLabelValue( 0, wxT("Камень") );
	m_gridMatrix->SetRowLabelValue( 1, wxT("Ножницы") );
	m_gridMatrix->SetRowLabelValue( 2, wxT("Бумага") );
	m_gridMatrix->SetRowLabelValue( 3, wxT("Максимум") );
	m_gridMatrix->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_gridMatrix->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	fgSizer2->Add( m_gridMatrix, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Вы:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer2->Add( m_staticText2, 1, wxALL|wxEXPAND, 5 );

	m_txtScorePlayer = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_txtScorePlayer->Wrap( -1 );
	bSizer2->Add( m_txtScorePlayer, 1, wxALL|wxEXPAND, 5 );

	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Бот:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer2->Add( m_staticText6, 1, wxALL|wxEXPAND, 5 );

	m_txtScoreBot = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_txtScoreBot->Wrap( -1 );
	bSizer2->Add( m_txtScoreBot, 1, wxALL|wxEXPAND, 5 );


	fgSizer2->Add( bSizer2, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Выбор бота:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer8->Add( m_staticText12, 1, wxALL|wxEXPAND, 5 );

	m_txtBotSelection = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_txtBotSelection->Wrap( -1 );
	bSizer8->Add( m_txtBotSelection, 1, wxALL|wxEXPAND, 5 );

	m_txtStatus = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_txtStatus->Wrap( -1 );
	bSizer8->Add( m_txtStatus, 1, wxALL|wxEXPAND, 5 );


	fgSizer2->Add( bSizer8, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	m_btnStone = new wxButton( this, wxID_ANY, wxT("&Камень"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_btnStone, 1, wxALL|wxEXPAND, 5 );

	m_btnScissors = new wxButton( this, wxID_ANY, wxT("&Ножницы"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_btnScissors, 1, wxALL|wxEXPAND, 5 );

	m_btnPaper = new wxButton( this, wxID_ANY, wxT("&Бумага"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_btnPaper, 1, wxALL|wxEXPAND, 5 );

	m_btnHelp = new wxButton( this, wxID_ANY, wxT("&Подсказка"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_btnHelp, 1, wxALL|wxEXPAND, 5 );

	m_btnRestart = new wxButton( this, wxID_ANY, wxT("&Сброс"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_btnRestart, 0, wxALL, 5 );


	fgSizer2->Add( bSizer4, 1, wxEXPAND, 5 );


	this->SetSizer( fgSizer2 );
	this->Layout();
	fgSizer2->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( IMainWindow::OnClose ) );
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( IMainWindow::OnInit ) );
	m_gridMatrix->Connect( wxEVT_GRID_CELL_CHANGED, wxGridEventHandler( IMainWindow::OnEditMatrix ), NULL, this );
	m_btnStone->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainWindow::OnClickStone ), NULL, this );
	m_btnScissors->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainWindow::OnClickScissors ), NULL, this );
	m_btnPaper->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainWindow::OnClickPaper ), NULL, this );
	m_btnHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainWindow::OnClickHelp ), NULL, this );
	m_btnRestart->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainWindow::OnClickReset ), NULL, this );
}

IMainWindow::~IMainWindow()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( IMainWindow::OnClose ) );
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( IMainWindow::OnInit ) );
	m_gridMatrix->Disconnect( wxEVT_GRID_CELL_CHANGED, wxGridEventHandler( IMainWindow::OnEditMatrix ), NULL, this );
	m_btnStone->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainWindow::OnClickStone ), NULL, this );
	m_btnScissors->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainWindow::OnClickScissors ), NULL, this );
	m_btnPaper->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainWindow::OnClickPaper ), NULL, this );
	m_btnHelp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainWindow::OnClickHelp ), NULL, this );
	m_btnRestart->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainWindow::OnClickReset ), NULL, this );

}
