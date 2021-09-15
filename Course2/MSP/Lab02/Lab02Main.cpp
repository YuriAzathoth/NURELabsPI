/***************************************************************
 * Name:      Lab02Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Yuri Zinchenko (yurii.zinchenko@nure.ua)
 * Created:   2019-05-17
 * Copyright: Yuri Zinchenko ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "Lab02Main.h"
#include <wx/msgdlg.h>
#include <cstdlib>
using namespace std;

//(*InternalHeaders(Lab02Frame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

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

//(*IdInit(Lab02Frame)
const long Lab02Frame::ID_STATICTEXT1 = wxNewId();
const long Lab02Frame::ID_COLOURPICKERCTRL1 = wxNewId();
const long Lab02Frame::ID_STATICTEXT2 = wxNewId();
const long Lab02Frame::ID_SLIDER1 = wxNewId();
const long Lab02Frame::ID_STATICTEXT3 = wxNewId();
const long Lab02Frame::ID_BUTTON1 = wxNewId();
const long Lab02Frame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Lab02Frame,wxFrame)
    //(*EventTable(Lab02Frame)
    //*)
END_EVENT_TABLE()

Lab02Frame::Lab02Frame(wxWindow* parent,wxWindowID id) :
	m_bMouseLeft	(false),
	m_bMouseRight	(false),
	m_bPrevPoint	(false),
	m_bInit			(false),
	m_SavedDC		(wxSize(CANVAS_WIDTH, CANVAS_HEIGHT))
{
    //(*Initialize(Lab02Frame)
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxCAPTION|wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(2, 0, 0, 0);
    FlexGridSizer2 = new wxFlexGridSizer(0, 6, 0, 0);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Pen color"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Color = new wxColourPickerCtrl(this, ID_COLOURPICKERCTRL1, wxColour(0,0,0), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL1"));
    FlexGridSizer2->Add(Color, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Pen size"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SizeSlider = new wxSlider(this, ID_SLIDER1, 1, 1, 50, wxDefaultPosition, wxSize(135,20), 0, wxDefaultValidator, _T("ID_SLIDER1"));
    FlexGridSizer2->Add(SizeSlider, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SizeText = new wxStaticText(this, ID_STATICTEXT3, _("1"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer2->Add(SizeText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonClear = new wxButton(this, ID_BUTTON1, _("Clear"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer2->Add(ButtonClear, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Canvas = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(480,320), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Canvas->SetBackgroundColour(wxColour(255,255,255));
    FlexGridSizer1->Add(Canvas, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_SLIDER1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&Lab02Frame::OnSizeSliderCmdSliderUpdated);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Lab02Frame::OnButtonClearClick);
    Canvas->Connect(wxEVT_PAINT,(wxObjectEventFunction)&Lab02Frame::OnCanvasPaint,0,this);
    Canvas->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&Lab02Frame::OnCanvasLeftDown,0,this);
    Canvas->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&Lab02Frame::OnCanvasLeftUp,0,this);
    Canvas->Connect(wxEVT_RIGHT_DOWN,(wxObjectEventFunction)&Lab02Frame::OnCanvasRightDown,0,this);
    Canvas->Connect(wxEVT_RIGHT_UP,(wxObjectEventFunction)&Lab02Frame::OnCanvasRightUp,0,this);
    Canvas->Connect(wxEVT_MOTION,(wxObjectEventFunction)&Lab02Frame::OnCanvasMouseMove,0,this);
    //*)
}

Lab02Frame::~Lab02Frame()
{
    //(*Destroy(Lab02Frame)
    //*)
}

void Lab02Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Lab02Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Lab02Frame::OnSizeSliderCmdSliderUpdated(wxScrollEvent& event)
{
	char szValue[4];
	sprintf(szValue, "%d", SizeSlider->GetValue());
	SizeText->SetLabel(szValue);
}

void Lab02Frame::OnCanvasMouseMove(wxMouseEvent& event)
{
	if (!m_bMouseLeft && !m_bMouseRight)
		return;

	wxWindowDC DC(Canvas);

	int iSize = SizeSlider->GetValue();

	wxColor DrawColor;

	if (m_bMouseLeft)
		DrawColor = Color->GetColour();
	else if (m_bMouseRight)
		DrawColor = 0xFFFFFF;

	DC.SetPen(wxPen(DrawColor, iSize));
	DC.SetBrush(wxBrush(DrawColor));

	if (m_bPrevPoint)
		DC.DrawLine(m_PrevPoint, event.GetPosition());
	else
	{
		DC.DrawPoint(m_PrevPoint);
		m_bPrevPoint = true;
	}

	m_PrevPoint = event.GetPosition();
}

void Lab02Frame::OnCanvasLeftDown(wxMouseEvent& event)
{
	m_bMouseLeft	= true;
}

void Lab02Frame::OnCanvasLeftUp(wxMouseEvent& event)
{
	m_bMouseLeft	= false;
	m_bPrevPoint	= false;
	SaveDc();
}

void Lab02Frame::OnCanvasRightDown(wxMouseEvent& event)
{
	m_bMouseRight	= true;
}

void Lab02Frame::OnCanvasRightUp(wxMouseEvent& event)
{
	m_bMouseRight	= false;
	m_bPrevPoint	= false;
	SaveDc();
}

void Lab02Frame::OnButtonClearClick(wxCommandEvent& event)
{
	wxWindowDC DC(Canvas);
	DC.Clear();
	SaveDc();
	Canvas->Refresh();
}

void Lab02Frame::OnCanvasPaint(wxPaintEvent& event)
{
	if (m_bInit)
	{
		wxPaintDC	DC(Canvas);
		wxMemoryDC	MDC;
		MDC.SelectObject(m_SavedDC);
		DC.Blit(0, 0, CANVAS_WIDTH, CANVAS_HEIGHT, &MDC, 0, 0);
		MDC.SelectObject(wxNullBitmap);
	}
	else
		m_bInit = true;
}

void Lab02Frame::SaveDc()
{
	wxWindowDC DC(Canvas);
	wxMemoryDC MDC;
	MDC.SelectObject(m_SavedDC);
	MDC.Blit(0, 0, CANVAS_WIDTH, CANVAS_HEIGHT, &DC, 0, 0);
	MDC.SelectObject(wxNullBitmap);
}
