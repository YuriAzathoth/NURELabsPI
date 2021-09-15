/***************************************************************
 * Name:      ISpline.cpp
 * Purpose:   Code for Spline Interface
 * Author:    ёрий «инченко (asmodeus.x5@outlook.com)
 * Created:   2018-12-1
 * Copyright: ёрий «инченко (2018)
 * License:   GPLv3
 **************************************************************/

#include "ISpline.h"

ISpline& ISpline::operator=(const ISpline& rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

void ISpline::Draw(wxPaintDC& rDC) const
{
	if (m_Vertexes.size() < 3)
		return;
	wxPen pen(m_clrBorder, 10);
	rDC.SetPen(pen);
	rDC.DrawSpline(&m_Vertexes);
}

void ISpline::DrawAsSelected(wxPaintDC& rDC) const
{
	if (m_Vertexes.size() < 3)
		return;

	int iRed = (int)round((double)m_clrBorder.Red() / 1.5);
	int iGreen = (int)round((double)m_clrBorder.Green() / 1.5);
	int iBlue = (int)round((double)m_clrBorder.Blue() / 1.5);
	wxColour clrBorder(iRed, iGreen, iBlue);
	wxPen penSelected(clrBorder, 10, wxPENSTYLE_DOT_DASH);
	rDC.SetPen(penSelected);

	rDC.DrawSpline(&m_Vertexes);
}
