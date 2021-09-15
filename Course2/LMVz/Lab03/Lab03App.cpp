/***************************************************************
 * Name:      Lab03App.cpp
 * Purpose:   Code for Application Class
 * Author:    Юрий Зинченко (asmodeus.x5@outlook.com)
 * Created:   2018-11-30
 * Copyright: Юрий Зинченко (2018)
 * License:   GPLv3
 **************************************************************/

#include "wx_pch.h"
#include "Lab03App.h"

//(*AppHeaders
#include "Lab03Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Lab03App);

bool Lab03App::OnInit()
{
	wxSetlocale(LC_ALL, "rus");
	//(*AppInitialize
	bool wxsOK = true;
	wxInitAllImageHandlers();
	if ( wxsOK )
	{
		Lab03Frame* Frame = new Lab03Frame(0);
		Frame->Show();
		SetTopWindow(Frame);
	}
	//*)
	return wxsOK;

}
