/***************************************************************
 * Name:      Lab03Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Юрий Зинченко (asmodeus.x5@outlook.com)
 * Created:   2018-11-30
 * Copyright: Юрий Зинченко (2018)
 * License:   GPLv3
 **************************************************************/

#include "wx_pch.h"
#include "Lab03Main.h"

//(*InternalHeaders(Lab03Frame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include <wx/dc.h>
#include <wx/msgdlg.h>
#include <wx/html/helpctrl.h>

#include "MapFormat.h"

//helper functions
enum wxbuildinfoformat
{
	short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
	wxString wxbuild(wxVERSION_STRING);

	if (format == long_f )
	{
#if defined(__WXMSW__)
		wxbuild << _T("-Windows");
#elif defined(__UNIX__)
		wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
		wxbuild << _T("-Unicode build");
#else
		wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
	}

	return wxbuild;
}

//(*IdInit(Lab03Frame)
const long Lab03Frame::ID_BITMAPBUTTON12 = wxNewId();
const long Lab03Frame::ID_BITMAPBUTTON13 = wxNewId();
const long Lab03Frame::ID_BITMAPBUTTON11 = wxNewId();
const long Lab03Frame::ID_BITMAPBUTTON14 = wxNewId();
const long Lab03Frame::ID_BITMAPBUTTON1 = wxNewId();
const long Lab03Frame::ID_BITMAPBUTTON2 = wxNewId();
const long Lab03Frame::ID_BITMAPBUTTON3 = wxNewId();
const long Lab03Frame::ID_BITMAPBUTTON4 = wxNewId();
const long Lab03Frame::ID_BITMAPBUTTON5 = wxNewId();
const long Lab03Frame::ID_BITMAPBUTTON6 = wxNewId();
const long Lab03Frame::ID_BITMAPBUTTON7 = wxNewId();
const long Lab03Frame::ID_BITMAPBUTTON8 = wxNewId();
const long Lab03Frame::ID_STATICTEXT1 = wxNewId();
const long Lab03Frame::ID_PANEL2 = wxNewId();
const long Lab03Frame::ID_BITMAPBUTTON9 = wxNewId();
const long Lab03Frame::ID_BITMAPBUTTON10 = wxNewId();
const long Lab03Frame::ID_TREECTRL1 = wxNewId();
const long Lab03Frame::ID_PANEL1 = wxNewId();
const long Lab03Frame::idMenuCreate = wxNewId();
const long Lab03Frame::idMenuOpen = wxNewId();
const long Lab03Frame::idMenuSave = wxNewId();
const long Lab03Frame::idMenuSaveAs = wxNewId();
const long Lab03Frame::idMenuClose = wxNewId();
const long Lab03Frame::idMenuQuit = wxNewId();
const long Lab03Frame::idMenuHelp = wxNewId();
const long Lab03Frame::idMenuAbout = wxNewId();
const long Lab03Frame::ID_STATUSBAR1 = wxNewId();
const long Lab03Frame::ID_TEXTENTRYDIALOG1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Lab03Frame,wxFrame)
	//(*EventTable(Lab03Frame)
	//*)
END_EVENT_TABLE()

#undef _
#define _(s) _T(s)

Lab03Frame::Lab03Frame(wxWindow* parent,wxWindowID id) :
	m_pMap(NULL),
	m_pLocale(NULL),
	m_wsCurrName(_T("")),
	m_pHoldVertex(NULL),
	m_bHoldVertex(false),
	m_eCurrTool(TOOL_NULL)
{
	m_pLocale = new wxLocale();
	m_pLocale->Init(wxLANGUAGE_RUSSIAN);

	//(*Initialize(Lab03Frame)
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer6;
	wxFlexGridSizer* FlexGridSizer7;
	wxGridSizer* GridSizer1;
	wxGridSizer* GridSizer2;
	wxMenu* Menu1;
	wxMenu* Menu2;
	wxMenuBar* MainMenuBar;
	wxMenuItem* MenuItem1;
	wxMenuItem* MenuItem2;

	Create(parent, wxID_ANY, _("Редактор карты местности"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(1280,768));
	MainPanel = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	FlexGridSizer4 = new wxFlexGridSizer(2, 0, 0, 0);
	GridSizer1 = new wxGridSizer(0, 5, 0, 0);
	BtnCreate = new wxBitmapButton(MainPanel, ID_BITMAPBUTTON12, wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\creater.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON12"));
	BtnCreate->SetBitmapSelected(wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\createl.png"))));
	BtnCreate->SetToolTip(_("Создать карту"));
	GridSizer1->Add(BtnCreate, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BtnOpen = new wxBitmapButton(MainPanel, ID_BITMAPBUTTON13, wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\openr.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON13"));
	BtnOpen->SetBitmapSelected(wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\openl.png"))));
	BtnOpen->SetToolTip(_("Открыть карту"));
	GridSizer1->Add(BtnOpen, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BtnSave = new wxBitmapButton(MainPanel, ID_BITMAPBUTTON11, wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\saver.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON11"));
	BtnSave->SetBitmapSelected(wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\savel.png"))));
	BtnSave->SetToolTip(_("Сохранить карту"));
	GridSizer1->Add(BtnSave, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	GridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BtnHelp = new wxBitmapButton(MainPanel, ID_BITMAPBUTTON14, wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\helpr.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON14"));
	BtnHelp->SetBitmapSelected(wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\helpl.png"))));
	BtnHelp->SetToolTip(_("Помощь"));
	GridSizer1->Add(BtnHelp, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer4->Add(GridSizer1, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
	FlexGridSizer5 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer2 = new wxFlexGridSizer(3, 0, 0, 0);
	FlexGridSizer3 = new wxFlexGridSizer(4, 2, 0, 0);
	BtnCity = new wxBitmapButton(MainPanel, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\cityr.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
	BtnCity->SetBitmapDisabled(wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\cityl.png"))));
	BtnCity->SetBitmapSelected(wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\cityl.png"))));
	BtnCity->SetToolTip(_("Город"));
	FlexGridSizer3->Add(BtnCity, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BtnVillage = new wxBitmapButton(MainPanel, ID_BITMAPBUTTON2, wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\villager.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
	BtnVillage->SetBitmapDisabled(wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\villagel.png"))));
	BtnVillage->SetBitmapSelected(wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\villagel.png"))));
	BtnVillage->SetToolTip(_("Посёлок"));
	FlexGridSizer3->Add(BtnVillage, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BtnRoad = new wxBitmapButton(MainPanel, ID_BITMAPBUTTON3, wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\roadr.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
	BtnRoad->SetBitmapDisabled(wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\roadl.png"))));
	BtnRoad->SetBitmapSelected(wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\roadl.png"))));
	BtnRoad->SetToolTip(_("Дорога"));
	FlexGridSizer3->Add(BtnRoad, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BtnRail = new wxBitmapButton(MainPanel, ID_BITMAPBUTTON4, wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\railroadr.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));
	BtnRail->SetBitmapDisabled(wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\railroadl.png"))));
	BtnRail->SetBitmapSelected(wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\railroadl.png"))));
	BtnRail->SetToolTip(_("Железная дорога"));
	FlexGridSizer3->Add(BtnRail, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BtnForest = new wxBitmapButton(MainPanel, ID_BITMAPBUTTON5, wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\forestr.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON5"));
	BtnForest->SetBitmapDisabled(wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\forestl.png"))));
	BtnForest->SetBitmapSelected(wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\forestl.png"))));
	BtnForest->SetToolTip(_("Хвойный лес"));
	FlexGridSizer3->Add(BtnForest, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BtnWood = new wxBitmapButton(MainPanel, ID_BITMAPBUTTON6, wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\woodr.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON6"));
	BtnWood->SetBitmapDisabled(wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\woodl.png"))));
	BtnWood->SetBitmapSelected(wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\woodl.png"))));
	BtnWood->SetToolTip(_("Лиственный лес"));
	FlexGridSizer3->Add(BtnWood, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BtnRiver = new wxBitmapButton(MainPanel, ID_BITMAPBUTTON7, wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\riverr.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON7"));
	BtnRiver->SetBitmapDisabled(wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\riverl.png"))));
	BtnRiver->SetBitmapSelected(wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\riverl.png"))));
	BtnRiver->SetToolTip(_("Река"));
	FlexGridSizer3->Add(BtnRiver, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BtnSea = new wxBitmapButton(MainPanel, ID_BITMAPBUTTON8, wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\sear.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON8"));
	BtnSea->SetBitmapDisabled(wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\seal.png"))));
	BtnSea->SetBitmapSelected(wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\seal.png"))));
	BtnSea->SetToolTip(_("Море"));
	FlexGridSizer3->Add(BtnSea, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer2->Add(FlexGridSizer3, 1, wxALL, 0);
	GridSizer2 = new wxGridSizer(0, 0, 0, 0);
	LabelTool = new wxStaticText(MainPanel, ID_STATICTEXT1, _("Редактирование"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont LabelToolFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	LabelTool->SetFont(LabelToolFont);
	GridSizer2->Add(LabelTool, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(GridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer5->Add(FlexGridSizer2, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 0);
	EditorPanel = new wxPanel(MainPanel, ID_PANEL2, wxDefaultPosition, wxSize(988,640), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	FlexGridSizer5->Add(EditorPanel, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 2);
	FlexGridSizer6 = new wxFlexGridSizer(2, 0, 0, 0);
	FlexGridSizer7 = new wxFlexGridSizer(0, 2, 0, 0);
	BtnObjDel = new wxBitmapButton(MainPanel, ID_BITMAPBUTTON9, wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\deleter.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON9"));
	BtnObjDel->SetBitmapSelected(wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\deletel.png"))));
	BtnObjDel->SetToolTip(_("Удалить выделенный объект"));
	FlexGridSizer7->Add(BtnObjDel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BtnObjRen = new wxBitmapButton(MainPanel, ID_BITMAPBUTTON10, wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\renamer.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON10"));
	BtnObjRen->SetBitmapSelected(wxBitmap(wxImage(_T("C:\\Work\\Univer\\LMVD\\Lab03\\Lab03\\iconssrc\\renamel.png"))));
	BtnObjRen->SetToolTip(_("Переименовать выделенный объект"));
	FlexGridSizer7->Add(BtnObjRen, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer6->Add(FlexGridSizer7, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 0);
	ObjsTreeCtrl = new wxTreeCtrl(MainPanel, ID_TREECTRL1, wxDefaultPosition, wxSize(140,580), wxTR_DEFAULT_STYLE, wxDefaultValidator, _T("ID_TREECTRL1"));
	wxTreeItemId ObjsTreeCtrl_Item1 = ObjsTreeCtrl->AddRoot(_T("Объекты"));
	FlexGridSizer6->Add(ObjsTreeCtrl, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 0);
	FlexGridSizer5->Add(FlexGridSizer6, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 0);
	FlexGridSizer4->Add(FlexGridSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	MainPanel->SetSizer(FlexGridSizer4);
	FlexGridSizer4->Fit(MainPanel);
	FlexGridSizer4->SetSizeHints(MainPanel);
	MainMenuBar = new wxMenuBar();
	Menu1 = new wxMenu();
	MenuItem3 = new wxMenuItem(Menu1, idMenuCreate, _("&Создать\tCtrl-N"), _("Создать новую карту"), wxITEM_NORMAL);
	Menu1->Append(MenuItem3);
	MenuItem4 = new wxMenuItem(Menu1, idMenuOpen, _("&Открыть\tCtrl-O"), _("Открыть существующую карту"), wxITEM_NORMAL);
	Menu1->Append(MenuItem4);
	MenuItem5 = new wxMenuItem(Menu1, idMenuSave, _("&Сохранить\tCtrl-S"), _("Сохранить текущую карту в файл"), wxITEM_NORMAL);
	Menu1->Append(MenuItem5);
	MenuItem7 = new wxMenuItem(Menu1, idMenuSaveAs, _("Сохранить &как\tCtrl-Shift-S"), _("Сохранить карту по другим именем"), wxITEM_NORMAL);
	Menu1->Append(MenuItem7);
	MenuItem8 = new wxMenuItem(Menu1, idMenuClose, _("&Закрыть\tCtrl-W"), _("Закрыть текущую карту"), wxITEM_NORMAL);
	Menu1->Append(MenuItem8);
	Menu1->AppendSeparator();
	MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("&Выход\tAlt-F4"), _("Выйти из программы"), wxITEM_NORMAL);
	Menu1->Append(MenuItem1);
	MainMenuBar->Append(Menu1, _("&Файл"));
	Menu2 = new wxMenu();
	MenuItem9 = new wxMenuItem(Menu2, idMenuHelp, _("&Справка\tF1"), _("Вызвать справку"), wxITEM_NORMAL);
	Menu2->Append(MenuItem9);
	MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("&О программе"), _("Показать информацию о программе"), wxITEM_NORMAL);
	Menu2->Append(MenuItem2);
	MainMenuBar->Append(Menu2, _("&Помощь"));
	SetMenuBar(MainMenuBar);
	StatusBar = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
	int __wxStatusBarWidths_1[1] = { -1 };
	int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
	StatusBar->SetFieldsCount(1,__wxStatusBarWidths_1);
	StatusBar->SetStatusStyles(1,__wxStatusBarStyles_1);
	SetStatusBar(StatusBar);
	NameTextDlg = new wxTextEntryDialog(this, _("Введите название:"), _("Введите название"), wxEmptyString, wxOK|wxCANCEL|wxCENTRE|wxWS_EX_VALIDATE_RECURSIVELY, wxDefaultPosition);
	Center();

	Connect(ID_BITMAPBUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Lab03Frame::OnNew);
	Connect(ID_BITMAPBUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Lab03Frame::OnOpen);
	Connect(ID_BITMAPBUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Lab03Frame::OnSave);
	Connect(ID_BITMAPBUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Lab03Frame::OnHelp);
	Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Lab03Frame::OnBtnCityClick);
	Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Lab03Frame::OnBtnVillageClick);
	Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Lab03Frame::OnBtnRoadClick);
	Connect(ID_BITMAPBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Lab03Frame::OnBtnRailClick);
	Connect(ID_BITMAPBUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Lab03Frame::OnBtnForestClick);
	Connect(ID_BITMAPBUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Lab03Frame::OnBtnWoodClick);
	Connect(ID_BITMAPBUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Lab03Frame::OnBtnRiverClick);
	Connect(ID_BITMAPBUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Lab03Frame::OnBtnSeaClick);
	EditorPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&Lab03Frame::OnEditorPanelPaint,0,this);
	EditorPanel->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&Lab03Frame::OnEditorPanelLeftDown,0,this);
	EditorPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&Lab03Frame::OnEditorPanelLeftUp,0,this);
	EditorPanel->Connect(wxEVT_RIGHT_DOWN,(wxObjectEventFunction)&Lab03Frame::OnEditorPanelRightDown,0,this);
	EditorPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&Lab03Frame::OnEditorPanelMouseMove,0,this);
	Connect(ID_BITMAPBUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Lab03Frame::OnBtnDelObjClick);
	Connect(ID_BITMAPBUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Lab03Frame::OnBtnObjRenClick);
	Connect(ID_TREECTRL1,wxEVT_COMMAND_TREE_SEL_CHANGED,(wxObjectEventFunction)&Lab03Frame::OnObjsTreeCtrlSelectionChanged);
	Connect(idMenuCreate,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Lab03Frame::OnNew);
	Connect(idMenuOpen,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Lab03Frame::OnOpen);
	Connect(idMenuSave,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Lab03Frame::OnSave);
	Connect(idMenuSaveAs,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Lab03Frame::OnSaveAs);
	Connect(idMenuClose,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Lab03Frame::OnCloseMap);
	Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Lab03Frame::OnQuit);
	Connect(idMenuHelp,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Lab03Frame::OnHelp);
	Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Lab03Frame::OnAbout);
	//*)

	m_pMap = new MapFormat();
}

Lab03Frame::~Lab03Frame()
{
	//(*Destroy(Lab03Frame)
	//*)

	if (m_pMap)
		delete m_pMap;
	if (m_pLocale)
		delete m_pLocale;
}

void Lab03Frame::OnEditorPanelLeftDown(wxMouseEvent& event)
{
	wxPoint msPos = event.GetPosition();
	if (m_eCurrTool != TOOL_NULL)
	{
		m_BufferNew.push_back(new wxPoint(msPos));
		switch(m_eCurrTool)
		{
		case TOOL_CITY: AddObject(ObjectManager::CITY); break;
		case TOOL_VILLAGE: AddObject(ObjectManager::VILLAGE); break;
		case TOOL_FOREST: AddObject(ObjectManager::FOREST); break;
		case TOOL_WOOD: AddObject(ObjectManager::WOOD); break;
		case TOOL_SEA: AddObject(ObjectManager::SEA); break;
		case TOOL_ROAD: AddObject(ObjectManager::ROAD); break;
		case TOOL_RAILWAY: AddObject(ObjectManager::RAIL); break;
		case TOOL_RIVER: AddObject(ObjectManager::RIVER); break;
		default: break;
		}
		Refresh();
	}
	else
	{
		wxPoint* vertex = GetVertex(msPos);
		if (vertex)
		{
			m_pHoldVertex = vertex;
			m_bHoldVertex = true;
			Refresh();
		}
	}
}

void Lab03Frame::OnEditorPanelLeftUp(wxMouseEvent& event)
{
	if (m_bHoldVertex)
	{
		m_pHoldVertex = NULL;
		m_bHoldVertex = false;
		Refresh();
	}
}

void Lab03Frame::OnEditorPanelMouseMove(wxMouseEvent& event)
{
	if (m_bHoldVertex)
	{
		wxPoint msPos = event.GetPosition();
        m_pHoldVertex->x = msPos.x;
        m_pHoldVertex->y = msPos.y;
        Refresh();
	}
}

void Lab03Frame::OnEditorPanelRightDown(wxMouseEvent& event)
{
	if (m_pMap->GetObjectManager()->Deselect())
		Refresh();

	if (!m_BufferNew.empty())
	{
		m_BufferNew.clear();
		UpdateTree();
		if (!m_wsCurrName.empty())
			m_wsCurrName = _("");
	}

	if (m_eCurrTool != TOOL_NULL)
	{
		m_eCurrTool = TOOL_NULL;
		UpdateMode();
	}
}

void Lab03Frame::OnObjsTreeCtrlSelectionChanged(wxTreeEvent& event)
{
	if (ObjsTreeCtrl->GetItemText(ObjsTreeCtrl->GetSelection()) == _("Объекты"))
		return;

	ObjectManager* pObjMgr = m_pMap->GetObjectManager();
	wxString name = ObjsTreeCtrl->GetItemText(ObjsTreeCtrl->GetSelection());

	pObjMgr->Deselect();
	pObjMgr->Select(name);

	Refresh();
}

void Lab03Frame::OnBtnDelObjClick(wxCommandEvent& event)
{
	if (ObjsTreeCtrl->GetItemText(ObjsTreeCtrl->GetSelection()) == _("Объекты"))
		return;

	ObjectManager* pObjMgr = m_pMap->GetObjectManager();
	wxString msg = _("Вы действительно хотите удалить ");
	msg += pObjMgr->GetObjectSelected()->GetName();
	msg += _("?");
	int iRes = wxMessageBox(msg, _("Удаление объекта"), wxYES | wxNO | wxCANCEL | wxCENTRE, this);
	if (iRes == wxYES)
	{
		pObjMgr->Remove();
		UpdateTree();
		Refresh();
	}
}

void Lab03Frame::OnBtnObjRenClick(wxCommandEvent& event)
{
	if (ObjsTreeCtrl->GetItemText(ObjsTreeCtrl->GetSelection()) == _("Объекты"))
		return;

	const wxString name = GetName();
	if (name == wxEmptyString)
		return;
    m_pMap->GetObjectManager()->Rename(name);

	UpdateTree();
	Refresh();
}

void Lab03Frame::OnQuit(wxCommandEvent& event)
{
	Close();
}

void Lab03Frame::OnAbout(wxCommandEvent& event)
{
	wxString msg = wxbuildinfo(long_f);
	wxMessageBox(msg, _("О программе"));
}

void Lab03Frame::ClearMap()
{
	if (m_pMap)
		delete m_pMap;
	m_pMap = NULL;
	m_pMap = new MapFormat();
	m_BufferNew.clear();
}

void Lab03Frame::AddObject(int eType)
{
	m_pMap->GetObjectManager()->AddObject(m_BufferNew, m_wsCurrName, eType);
}

wxPoint* Lab03Frame::GetVertex(const wxPoint& rCoord) const
{
	IObject* pSelObj = m_pMap->GetObjectManager()->GetObjectSelected();
	if (!pSelObj)
		return NULL;

    wxPointList shape = pSelObj->GetVertexes();
    for (auto it = shape.begin(); it != shape.end(); it++)
	{
        if ((*it)->x > (rCoord.x - 10) && (*it)->x < (rCoord.x + 10) &&
			(*it)->y > (rCoord.y - 10) && (*it)->y < (rCoord.y + 10))
			return *it;
	}
	return NULL;
}

void Lab03Frame::OnBtnCityClick(wxCommandEvent& event)
{
	SetTool(TOOL_CITY);
}

void Lab03Frame::OnBtnVillageClick(wxCommandEvent& event)
{
	SetTool(TOOL_VILLAGE);
}

void Lab03Frame::OnBtnRoadClick(wxCommandEvent& event)
{
	SetTool(TOOL_ROAD);
}

void Lab03Frame::OnBtnRailClick(wxCommandEvent& event)
{
	SetTool(TOOL_RAILWAY);
}

void Lab03Frame::OnBtnForestClick(wxCommandEvent& event)
{
	SetTool(TOOL_FOREST);
}

void Lab03Frame::OnBtnWoodClick(wxCommandEvent& event)
{
	SetTool(TOOL_WOOD);
}

void Lab03Frame::OnBtnRiverClick(wxCommandEvent& event)
{
	SetTool(TOOL_RIVER);
}

void Lab03Frame::OnBtnSeaClick(wxCommandEvent& event)
{
	SetTool(TOOL_SEA);
}

void Lab03Frame::OnEditorPanelPaint(wxPaintEvent& event)
{
	wxPaintDC dc(EditorPanel);
	dc.Clear();

	wxColour clrBkgrnd = m_pMap->GetBackgroundColor();
	wxPen penBkgrnd(clrBkgrnd, 0, wxPENSTYLE_TRANSPARENT);
	wxBrush brushBkgrnd(clrBkgrnd);
	dc.SetPen(penBkgrnd);
	dc.SetBrush(brushBkgrnd);
	dc.DrawRectangle(0, 0, 988, 640);

	m_pMap->Draw(dc);

	if (m_bHoldVertex && m_pHoldVertex)
	{
		wxPen pen(wxColour(0, 0, 0), 1);
		wxBrush brush(wxColour(255, 255, 0));
		dc.SetPen(pen);
		dc.SetBrush(brush);
        dc.DrawRectangle(m_pHoldVertex->x - 5, m_pHoldVertex->y - 5, 10, 10);
	}
}

void Lab03Frame::UpdateTree()
{
	ObjsTreeCtrl->DeleteAllItems();
	ObjsTreeCtrl->AddRoot(_("Объекты"));
	auto objs = m_pMap->GetObjectManager()->GetObjects();
	for (auto it = objs.cbegin(); it != objs.cend(); it++)
		ObjsTreeCtrl->AppendItem(ObjsTreeCtrl->GetRootItem(), (*it).first);
	ObjsTreeCtrl->ExpandAll();
}

void Lab03Frame::UpdateMode()
{
	switch (m_eCurrTool)
	{
	case TOOL_NULL:
		BtnCity->Enable();
		BtnVillage->Enable();
		BtnRoad->Enable();
		BtnRail->Enable();
		BtnForest->Enable();
		BtnWood->Enable();
		BtnRiver->Enable();
		BtnSea->Enable();
		LabelTool->SetLabel(_("Редактирование"));
		break;
	case TOOL_CITY:
		BtnCity->Disable();
		BtnVillage->Enable();
		BtnRoad->Enable();
		BtnRail->Enable();
		BtnForest->Enable();
		BtnWood->Enable();
		BtnRiver->Enable();
		BtnSea->Enable();
		LabelTool->SetLabel(_("Город"));
		break;
	case TOOL_VILLAGE:
		BtnCity->Enable();
		BtnVillage->Disable();
		BtnRoad->Enable();
		BtnRail->Enable();
		BtnForest->Enable();
		BtnWood->Enable();
		BtnRiver->Enable();
		BtnSea->Enable();
		LabelTool->SetLabel(_("Посёлок/Село"));
		break;
	case TOOL_ROAD:
		BtnCity->Enable();
		BtnVillage->Enable();
		BtnRoad->Disable();
		BtnRail->Enable();
		BtnForest->Enable();
		BtnWood->Enable();
		BtnRiver->Enable();
		BtnSea->Enable();
		LabelTool->SetLabel(_("Дорога"));
		break;
	case TOOL_RAILWAY:
		BtnCity->Enable();
		BtnVillage->Enable();
		BtnRoad->Enable();
		BtnRail->Disable();
		BtnForest->Enable();
		BtnWood->Enable();
		BtnRiver->Enable();
		BtnSea->Enable();
		LabelTool->SetLabel(_("Ж/Д пути"));
		break;
	case TOOL_FOREST:
		BtnCity->Enable();
		BtnVillage->Enable();
		BtnRoad->Enable();
		BtnRail->Enable();
		BtnForest->Disable();
		BtnWood->Enable();
		BtnRiver->Enable();
		BtnSea->Enable();
		LabelTool->SetLabel(_("Хвойный лес"));
		break;
	case TOOL_WOOD:
		BtnCity->Enable();
		BtnVillage->Enable();
		BtnRoad->Enable();
		BtnRail->Enable();
		BtnForest->Enable();
		BtnWood->Disable();
		BtnRiver->Enable();
		BtnSea->Enable();
		LabelTool->SetLabel(_("Лиственный лес"));
		break;
	case TOOL_RIVER:
		BtnCity->Enable();
		BtnVillage->Enable();
		BtnRoad->Enable();
		BtnRail->Enable();
		BtnForest->Enable();
		BtnWood->Enable();
		BtnRiver->Disable();
		BtnSea->Enable();
		LabelTool->SetLabel(_("Река"));
		break;
	case TOOL_SEA:
		BtnCity->Enable();
		BtnVillage->Enable();
		BtnRoad->Enable();
		BtnRail->Enable();
		BtnForest->Enable();
		BtnWood->Enable();
		BtnRiver->Enable();
		BtnSea->Disable();
		LabelTool->SetLabel(_("Озеро/Море"));
		break;
	}
}

void Lab03Frame::Save()
{
	if (!m_pMap->IsNew())
		m_pMap->Save();
	else
	{
		wxFileDialog* dlg = new wxFileDialog(this);
		dlg->SetWildcard(_("Карта XML (*.xml)|*.xml"));
		if (dlg->ShowModal() == wxID_OK)
			m_pMap->Save(dlg->GetPath());
	}
}

void Lab03Frame::SaveAs()
{
	wxFileDialog* dlg = new wxFileDialog(this);
	dlg->SetWildcard(_("Карта XML (*.xml)|*.xml"));
	if (dlg->ShowModal() == wxID_OK)
		m_pMap->Save(dlg->GetPath());
}

void Lab03Frame::OnNew(wxCommandEvent& event)
{
	if (m_pMap)
	{
		if (m_pMap->IsModified())
		{
			int iRes = wxMessageBox(
						   _("Текщая карта не сохранена.\nСоздание новой карты приведёт к потерям всех изменений после последнего сохранения.\nДа - сохранить текущую карту и создать новую\nНет - создать новую карту без сохранения текущей\nОтмена - не создавать новую карту и не сохранять текущую."),
						   _("Карта не сохранена"),
						   wxYES|wxNO|wxCANCEL|wxCENTRE);
			switch (iRes)
			{
			case wxYES:
				Save();
			case wxNO:
				return;
			}
		}
	}
	ClearMap();
	UpdateMode();
	Refresh();
}

void Lab03Frame::OnOpen(wxCommandEvent& event)
{
	if (m_pMap)
	{
		if (m_pMap->IsModified())
		{
			int iRes = wxMessageBox(
						   _("Текщая карта не сохранена.\nЗагрузка другой карты приведёт к потерям всех изменений после последнего сохранения.\nДа - сохранить текущую карту и создать новую\nНет - создать новую карту без сохранения текущей\nОтмена - не создавать новую карту и не сохранять текущую."),
						   _("Карта не сохранена"),
						   wxYES|wxNO|wxCANCEL|wxCENTRE);
			switch (iRes)
			{
			case wxYES:
				Save();
			case wxNO:
				return;
			}
		}
	}

	wxFileDialog* dlg = new wxFileDialog(this);
	dlg->SetWildcard(_("Карта XML (*.xml)|*.xml"));
	if (dlg->ShowModal() == wxID_OK)
		m_pMap->Open(dlg->GetPath());
	else
		return;

	ClearMap();
	m_pMap->Open(dlg->GetPath());

	UpdateMode();
	UpdateTree();
	Refresh();
}

void Lab03Frame::OnSave(wxCommandEvent& event)
{
	Save();
}

void Lab03Frame::OnSaveAs(wxCommandEvent& event)
{
	SaveAs();
}

void Lab03Frame::OnCloseMap(wxCommandEvent& event)
{
	if (m_pMap)
		if (m_pMap->IsModified())
		{
			int iRes = wxMessageBox(
						   _("Текщая карта не сохранена.\nЗакрытие этой карты приведёт к потерям всех изменений после последнего сохранения.\nДа - сохранить текущую карту и создать новую\nНет - создать новую карту без сохранения текущей\nОтмена - не создавать новую карту и не сохранять текущую."),
						   _("Карта не сохранена"),
						   wxYES|wxNO|wxCANCEL|wxCENTRE);
			switch (iRes)
			{
			case wxYES:
				Save();
			case wxNO:
				return;
			}
		}
	ClearMap();
	UpdateMode();
	Refresh();
}

void Lab03Frame::OnHelp(wxCommandEvent& event)
{
	wxHtmlModalHelp help(this, _("./help/help.chm"));
}
