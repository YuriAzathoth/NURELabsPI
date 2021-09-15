///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GeneratedWindows.h"

///////////////////////////////////////////////////////////////////////////

IMainDialog::IMainDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	m_btnUserRegistration = new wxButton( this, wxID_ANY, wxT("&Пользователи"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_btnUserRegistration, 0, wxALL|wxEXPAND, 5 );

	m_btnCriterionEdit = new wxButton( this, wxID_ANY, wxT("&Критерии"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_btnCriterionEdit, 0, wxALL|wxEXPAND, 5 );

	m_btnEditAlternatives = new wxButton( this, wxID_ANY, wxT("&Альтернативы"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_btnEditAlternatives, 0, wxALL|wxEXPAND, 5 );


	fgSizer6->Add( bSizer4, 1, wxEXPAND, 5 );

	m_staticline8 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer6->Add( m_staticline8, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer101;
	bSizer101 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("Пользователь"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer101->Add( m_staticText14, 1, wxALL|wxEXPAND, 5 );

	wxArrayString m_selUserNameChoices;
	m_selUserName = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_selUserNameChoices, 0 );
	m_selUserName->SetSelection( 0 );
	bSizer101->Add( m_selUserName, 1, wxALL|wxEXPAND, 5 );


	fgSizer6->Add( bSizer101, 1, wxEXPAND, 5 );

	m_gridVitality = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_gridVitality->CreateGrid( 0, 1 );
	m_gridVitality->EnableEditing( true );
	m_gridVitality->EnableGridLines( true );
	m_gridVitality->EnableDragGridSize( false );
	m_gridVitality->SetMargins( 0, 0 );

	// Columns
	m_gridVitality->EnableDragColMove( false );
	m_gridVitality->EnableDragColSize( true );
	m_gridVitality->SetColLabelSize( 30 );
	m_gridVitality->SetColLabelValue( 0, wxT("Важность") );
	m_gridVitality->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_gridVitality->AutoSizeRows();
	m_gridVitality->EnableDragRowSize( true );
	m_gridVitality->SetRowLabelSize( 80 );
	m_gridVitality->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_gridVitality->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	fgSizer6->Add( m_gridVitality, 0, wxALL, 5 );

	m_btnSaveWeights = new wxButton( this, wxID_ANY, wxT("&Сохранить"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer6->Add( m_btnSaveWeights, 0, wxALL, 5 );

	m_staticline4 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer6->Add( m_staticline4, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText141 = new wxStaticText( this, wxID_ANY, wxT("Порог"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText141->Wrap( -1 );
	bSizer14->Add( m_staticText141, 1, wxALL|wxEXPAND, 5 );

	m_spinThreshold = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 50 );
	bSizer14->Add( m_spinThreshold, 1, wxALL|wxEXPAND, 5 );


	fgSizer6->Add( bSizer14, 1, wxEXPAND, 5 );

	m_gridResult = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_gridResult->CreateGrid( 0, 2 );
	m_gridResult->EnableEditing( true );
	m_gridResult->EnableGridLines( true );
	m_gridResult->EnableDragGridSize( false );
	m_gridResult->SetMargins( 0, 0 );

	// Columns
	m_gridResult->EnableDragColMove( false );
	m_gridResult->EnableDragColSize( true );
	m_gridResult->SetColLabelSize( 30 );
	m_gridResult->SetColLabelValue( 0, wxT("Оценка") );
	m_gridResult->SetColLabelValue( 1, wxT("Ранг") );
	m_gridResult->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_gridResult->AutoSizeRows();
	m_gridResult->EnableDragRowSize( true );
	m_gridResult->SetRowLabelSize( 80 );
	m_gridResult->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_gridResult->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	fgSizer6->Add( m_gridResult, 0, wxALL, 5 );

	m_staticline6 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer6->Add( m_staticline6, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_btnCalcLab2 = new wxButton( this, wxID_ANY, wxT("&Lab2"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_btnCalcLab2, 1, wxALL|wxEXPAND, 5 );

	m_btnCalcLab3 = new wxButton( this, wxID_ANY, wxT("&Lab3"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_btnCalcLab3, 1, wxALL|wxEXPAND, 5 );

	m_btnCalcLab4 = new wxButton( this, wxID_ANY, wxT("&Lab4"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_btnCalcLab4, 1, wxALL|wxEXPAND, 5 );


	fgSizer6->Add( bSizer10, 1, wxEXPAND, 5 );


	this->SetSizer( fgSizer6 );
	this->Layout();
	fgSizer6->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( IMainDialog::OnClose ) );
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( IMainDialog::OnInit ) );
	m_btnUserRegistration->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnClickEditUsers ), NULL, this );
	m_btnCriterionEdit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnClickEditCriterions ), NULL, this );
	m_btnEditAlternatives->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnClickEditAlternatives ), NULL, this );
	m_selUserName->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( IMainDialog::OnSelectName ), NULL, this );
	m_btnSaveWeights->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnSaveWeights ), NULL, this );
	m_btnCalcLab2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnClickCalcLab2 ), NULL, this );
	m_btnCalcLab3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnClickCalcLab3 ), NULL, this );
	m_btnCalcLab4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnClickCalcLab4 ), NULL, this );
}

IMainDialog::~IMainDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( IMainDialog::OnClose ) );
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( IMainDialog::OnInit ) );
	m_btnUserRegistration->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnClickEditUsers ), NULL, this );
	m_btnCriterionEdit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnClickEditCriterions ), NULL, this );
	m_btnEditAlternatives->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnClickEditAlternatives ), NULL, this );
	m_selUserName->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( IMainDialog::OnSelectName ), NULL, this );
	m_btnSaveWeights->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnSaveWeights ), NULL, this );
	m_btnCalcLab2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnClickCalcLab2 ), NULL, this );
	m_btnCalcLab3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnClickCalcLab3 ), NULL, this );
	m_btnCalcLab4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IMainDialog::OnClickCalcLab4 ), NULL, this );

}

IComparisonDialog::IComparisonDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_gridPair = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_gridPair->CreateGrid( 0, 2 );
	m_gridPair->EnableEditing( false );
	m_gridPair->EnableGridLines( true );
	m_gridPair->EnableDragGridSize( false );
	m_gridPair->SetMargins( 0, 0 );

	// Columns
	m_gridPair->AutoSizeColumns();
	m_gridPair->EnableDragColMove( false );
	m_gridPair->EnableDragColSize( true );
	m_gridPair->SetColLabelSize( 30 );
	m_gridPair->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_gridPair->AutoSizeRows();
	m_gridPair->EnableDragRowSize( true );
	m_gridPair->SetRowLabelSize( 80 );
	m_gridPair->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_gridPair->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	fgSizer6->Add( m_gridPair, 0, wxALL, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	m_btnSelect1 = new wxButton( this, wxID_ANY, wxT("Выбрать"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_btnSelect1, 1, wxALL|wxEXPAND, 5 );

	m_btnSelect2 = new wxButton( this, wxID_ANY, wxT("Выбрать"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_btnSelect2, 1, wxALL|wxEXPAND, 5 );


	fgSizer6->Add( bSizer8, 1, wxEXPAND, 5 );


	this->SetSizer( fgSizer6 );
	this->Layout();
	fgSizer6->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( IComparisonDialog::OnInit ) );
	m_btnSelect1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IComparisonDialog::OnSelect1Click ), NULL, this );
	m_btnSelect2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IComparisonDialog::OnSelect2Click ), NULL, this );
}

IComparisonDialog::~IComparisonDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( IComparisonDialog::OnInit ) );
	m_btnSelect1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IComparisonDialog::OnSelect1Click ), NULL, this );
	m_btnSelect2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IComparisonDialog::OnSelect2Click ), NULL, this );

}

IUsersDialog::IUsersDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxGridSizer* gSizer8;
	gSizer8 = new wxGridSizer( 0, 2, 0, 0 );

	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("Имя пользователя"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	gSizer8->Add( m_staticText16, 0, wxALL, 5 );

	m_cmbName = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	gSizer8->Add( m_cmbName, 0, wxALL|wxEXPAND, 5 );

	m_staticText18 = new wxStaticText( this, wxID_ANY, wxT("Компетентность"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	gSizer8->Add( m_staticText18, 0, wxALL, 5 );

	m_spinRange = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1, 0.500000, 0.1 );
	m_spinRange->SetDigits( 0 );
	gSizer8->Add( m_spinRange, 0, wxALL|wxEXPAND, 5 );


	fgSizer4->Add( gSizer8, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	m_btnCreate = new wxButton( this, wxID_ANY, wxT("&Создать"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_btnCreate, 0, wxALL, 5 );

	m_btnEdit = new wxButton( this, wxID_ANY, wxT("&Изменить"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_btnEdit, 0, wxALL, 5 );

	m_btnDelete = new wxButton( this, wxID_ANY, wxT("&Удалить"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_btnDelete, 0, wxALL, 5 );


	fgSizer4->Add( bSizer6, 1, wxEXPAND, 5 );


	this->SetSizer( fgSizer4 );
	this->Layout();
	fgSizer4->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( IUsersDialog::OnInit ) );
	m_cmbName->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( IUsersDialog::OnSelectName ), NULL, this );
	m_btnCreate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IUsersDialog::OnClickCreate ), NULL, this );
	m_btnEdit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IUsersDialog::OnClickEdit ), NULL, this );
	m_btnDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IUsersDialog::OnClickDelete ), NULL, this );
}

IUsersDialog::~IUsersDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( IUsersDialog::OnInit ) );
	m_cmbName->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( IUsersDialog::OnSelectName ), NULL, this );
	m_btnCreate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IUsersDialog::OnClickCreate ), NULL, this );
	m_btnEdit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IUsersDialog::OnClickEdit ), NULL, this );
	m_btnDelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IUsersDialog::OnClickDelete ), NULL, this );

}

ICriterionsDialog::ICriterionsDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxGridSizer* gSizer10;
	gSizer10 = new wxGridSizer( 0, 2, 0, 0 );

	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("Название"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	gSizer10->Add( m_staticText14, 0, wxALL, 5 );

	m_cmbName = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	gSizer10->Add( m_cmbName, 0, wxALL|wxEXPAND, 5 );

	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("Ранг"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	gSizer10->Add( m_staticText16, 0, wxALL, 5 );

	m_spinRange = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0, 1 );
	m_spinRange->SetDigits( 0 );
	gSizer10->Add( m_spinRange, 0, wxALL|wxEXPAND, 5 );

	m_staticText18 = new wxStaticText( this, wxID_ANY, wxT("Важность (0 - 10)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	gSizer10->Add( m_staticText18, 0, wxALL, 5 );

	m_spinWeight = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 5, 1 );
	m_spinWeight->SetDigits( 0 );
	gSizer10->Add( m_spinWeight, 0, wxALL|wxEXPAND, 5 );

	m_staticText20 = new wxStaticText( this, wxID_ANY, wxT("Тип"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	gSizer10->Add( m_staticText20, 0, wxALL, 5 );

	wxString m_selTypeChoices[] = { wxT("Качественный"), wxT("Количественный"), wxEmptyString, wxEmptyString };
	int m_selTypeNChoices = sizeof( m_selTypeChoices ) / sizeof( wxString );
	m_selType = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_selTypeNChoices, m_selTypeChoices, 0 );
	m_selType->SetSelection( 0 );
	gSizer10->Add( m_selType, 0, wxALL|wxEXPAND, 5 );

	m_staticText22 = new wxStaticText( this, wxID_ANY, wxT("Оптимальность"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	gSizer10->Add( m_staticText22, 0, wxALL, 5 );

	wxString m_selOptimalChoices[] = { wxT("Минимум"), wxT("Максимум"), wxEmptyString, wxEmptyString };
	int m_selOptimalNChoices = sizeof( m_selOptimalChoices ) / sizeof( wxString );
	m_selOptimal = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_selOptimalNChoices, m_selOptimalChoices, 0 );
	m_selOptimal->SetSelection( 1 );
	gSizer10->Add( m_selOptimal, 0, wxALL|wxEXPAND, 5 );

	m_staticText24 = new wxStaticText( this, wxID_ANY, wxT("Единицы измерения"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	gSizer10->Add( m_staticText24, 0, wxALL, 5 );

	m_cmbUnits = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	gSizer10->Add( m_cmbUnits, 0, wxALL|wxEXPAND, 5 );

	m_staticText26 = new wxStaticText( this, wxID_ANY, wxT("Тип шкалы"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	gSizer10->Add( m_staticText26, 0, wxALL, 5 );

	m_cmbScaleType = new wxComboBox( this, wxID_ANY, wxT("Численные"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_cmbScaleType->Append( wxT("Численные") );
	m_cmbScaleType->Append( wxT("Бальные") );
	m_cmbScaleType->Append( wxT("Интервальная") );
	m_cmbScaleType->Append( wxEmptyString );
	m_cmbScaleType->Append( wxEmptyString );
	m_cmbScaleType->SetSelection( 0 );
	gSizer10->Add( m_cmbScaleType, 0, wxALL|wxEXPAND, 5 );


	fgSizer6->Add( gSizer10, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	m_btnCreate = new wxButton( this, wxID_ANY, wxT("&Создать"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_btnCreate, 0, wxALL, 5 );

	m_btnEdit = new wxButton( this, wxID_ANY, wxT("&Изменить"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_btnEdit, 0, wxALL, 5 );

	m_btnDelete = new wxButton( this, wxID_ANY, wxT("&Удалить"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_btnDelete, 0, wxALL, 5 );


	fgSizer6->Add( bSizer6, 1, wxEXPAND, 5 );


	this->SetSizer( fgSizer6 );
	this->Layout();
	fgSizer6->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( ICriterionsDialog::OnInit ) );
	m_cmbName->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( ICriterionsDialog::OnSelectName ), NULL, this );
	m_btnCreate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ICriterionsDialog::OnClickCreate ), NULL, this );
	m_btnEdit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ICriterionsDialog::OnClickEdit ), NULL, this );
	m_btnDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ICriterionsDialog::OnClickDelete ), NULL, this );
}

ICriterionsDialog::~ICriterionsDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( ICriterionsDialog::OnInit ) );
	m_cmbName->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( ICriterionsDialog::OnSelectName ), NULL, this );
	m_btnCreate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ICriterionsDialog::OnClickCreate ), NULL, this );
	m_btnEdit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ICriterionsDialog::OnClickEdit ), NULL, this );
	m_btnDelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ICriterionsDialog::OnClickDelete ), NULL, this );

}

IAlternativesDialog::IAlternativesDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 5, 1, 0, 0 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("Имя альтернативы"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer12->Add( m_staticText14, 1, wxALL, 5 );

	m_cmbName = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer12->Add( m_cmbName, 1, wxALL, 5 );


	fgSizer8->Add( bSizer12, 1, wxEXPAND, 5 );

	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer8->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );

	m_gridMarks = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_gridMarks->CreateGrid( 0, 5 );
	m_gridMarks->EnableEditing( true );
	m_gridMarks->EnableGridLines( true );
	m_gridMarks->EnableDragGridSize( false );
	m_gridMarks->SetMargins( 0, 0 );

	// Columns
	m_gridMarks->EnableDragColMove( false );
	m_gridMarks->EnableDragColSize( true );
	m_gridMarks->SetColLabelSize( 30 );
	m_gridMarks->SetColLabelValue( 0, wxT("Критерий") );
	m_gridMarks->SetColLabelValue( 1, wxT("Название") );
	m_gridMarks->SetColLabelValue( 2, wxT("Ранг") );
	m_gridMarks->SetColLabelValue( 3, wxT("Оценка") );
	m_gridMarks->SetColLabelValue( 4, wxT("Нормал. оценка") );
	m_gridMarks->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_gridMarks->AutoSizeRows();
	m_gridMarks->EnableDragRowSize( true );
	m_gridMarks->SetRowLabelSize( 80 );
	m_gridMarks->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_gridMarks->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	fgSizer8->Add( m_gridMarks, 1, wxALL|wxEXPAND, 5 );

	m_staticline4 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer8->Add( m_staticline4, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	m_btnCreate = new wxButton( this, wxID_ANY, wxT("&Создать"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_btnCreate, 0, wxALL, 5 );

	m_btnEdit = new wxButton( this, wxID_ANY, wxT("&Изменить"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_btnEdit, 0, wxALL, 5 );

	m_btnDelete = new wxButton( this, wxID_ANY, wxT("&Удалить"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_btnDelete, 0, wxALL, 5 );


	fgSizer8->Add( bSizer8, 1, wxEXPAND, 5 );


	this->SetSizer( fgSizer8 );
	this->Layout();
	fgSizer8->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( IAlternativesDialog::OnInit ) );
	m_cmbName->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( IAlternativesDialog::OnSelectName ), NULL, this );
	m_btnCreate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IAlternativesDialog::OnClickCreate ), NULL, this );
	m_btnEdit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IAlternativesDialog::OnClickEdit ), NULL, this );
	m_btnDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IAlternativesDialog::OnClickDelete ), NULL, this );
}

IAlternativesDialog::~IAlternativesDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( IAlternativesDialog::OnInit ) );
	m_cmbName->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( IAlternativesDialog::OnSelectName ), NULL, this );
	m_btnCreate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IAlternativesDialog::OnClickCreate ), NULL, this );
	m_btnEdit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IAlternativesDialog::OnClickEdit ), NULL, this );
	m_btnDelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IAlternativesDialog::OnClickDelete ), NULL, this );

}

ICalculateDialog::ICalculateDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("Пользователь"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer18->Add( m_staticText16, 0, wxALL, 5 );

	wxArrayString m_selUserChoices;
	m_selUser = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_selUserChoices, 0 );
	m_selUser->SetSelection( 0 );
	bSizer18->Add( m_selUser, 0, wxALL, 5 );


	fgSizer8->Add( bSizer18, 1, wxEXPAND, 5 );


	this->SetSizer( fgSizer8 );
	this->Layout();
	fgSizer8->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( ICalculateDialog::OnInit ) );
}

ICalculateDialog::~ICalculateDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( ICalculateDialog::OnInit ) );

}
