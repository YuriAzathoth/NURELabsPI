/***************************************************************
 * Name:      Lab02App.cpp
 * Purpose:   Code for Application Class
 * Author:    Yuri Zinchenko (yurii.zinchenko@nure.ua)
 * Created:   2019-05-17
 * Copyright: Yuri Zinchenko ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "Lab02App.h"

#include <clocale>

//(*AppHeaders
#include "Lab02Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Lab02App);

bool Lab02App::OnInit()
{
	std::setlocale(LC_ALL, "Russian");
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    Lab02Frame* Frame = new Lab02Frame(0);
    Frame->Show();
    SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
