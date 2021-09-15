/***************************************************************
 * Name:      Lab02Main.h
 * Purpose:   Defines Application Frame
 * Author:    Yuri Zinchenko (yurii.zinchenko@nure.ua)
 * Created:   2019-05-17
 * Copyright: Yuri Zinchenko ()
 * License:
 **************************************************************/

#ifndef LAB02MAIN_H
#define LAB02MAIN_H

//(*Headers(Lab02Frame)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/slider.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/clrpicker.h>
//*)

class Lab02Frame: public wxFrame
{
    public:

        Lab02Frame(wxWindow* parent,wxWindowID id = -1);
        virtual		~Lab02Frame();

    private:

    	void		SaveDc();

    	bool		m_bMouseLeft;
    	bool		m_bMouseRight;
    	bool		m_bPrevPoint;
    	bool		m_bInit;
    	wxPoint		m_PrevPoint;
    	wxBitmap	m_SavedDC;

    	static constexpr int CANVAS_WIDTH	= 480;
    	static constexpr int CANVAS_HEIGHT	= 320;

        //(*Handlers(Lab02Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnSizeSliderCmdSliderUpdated(wxScrollEvent& event);
        void OnCanvasMouseMove(wxMouseEvent& event);
        void OnCanvasLeftDown(wxMouseEvent& event);
        void OnCanvasLeftUp(wxMouseEvent& event);
        void OnCanvasRightDown(wxMouseEvent& event);
        void OnCanvasRightUp(wxMouseEvent& event);
        void OnButtonClearClick(wxCommandEvent& event);
        void OnCanvasPaint(wxPaintEvent& event);
        //*)

        //(*Identifiers(Lab02Frame)
        static const long ID_STATICTEXT1;
        static const long ID_COLOURPICKERCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_SLIDER1;
        static const long ID_STATICTEXT3;
        static const long ID_BUTTON1;
        static const long ID_PANEL1;
        //*)

        //(*Declarations(Lab02Frame)
        wxButton* ButtonClear;
        wxStaticText* SizeText;
        wxStaticText* StaticText1;
        wxPanel* Canvas;
        wxStaticText* StaticText2;
        wxColourPickerCtrl* Color;
        wxSlider* SizeSlider;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // LAB02MAIN_H
