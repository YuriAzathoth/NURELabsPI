/***************************************************************
 * Name:      IShape.cpp
 * Purpose:   Code for Shape Interface
 * Author:    ёрий «инченко (asmodeus.x5@outlook.com)
 * Created:   2018-11-30
 * Copyright: ёрий «инченко (2018)
 * License:   GPLv3
 **************************************************************/

#include "IShape.h"

IShape& IShape::operator=(const IShape& rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

void IShape::Draw(wxPaintDC& rDC) const
{
	wxPen pen(m_clrBorder, 2);
	wxBrush brush(m_clrFill);
	rDC.SetPen(pen);
	rDC.SetBrush(brush);
	rDC.DrawPolygon(&m_Vertexes);
}

void IShape::DrawAsSelected(wxPaintDC& rDC) const
{
	int iRed = (int)round((double)m_clrBorder.Red() / 1.5);
	int iGreen = (int)round((double)m_clrBorder.Green() / 1.5);
	int iBlue = (int)round((double)m_clrBorder.Blue() / 1.5);
	wxColour clrBorder(iRed, iGreen, iBlue);
	wxPen penSelected(clrBorder, 2, wxPENSTYLE_DOT_DASH);
	rDC.SetPen(penSelected);

	iRed = (int)round((double)m_clrFill.Red() / 1.5);
	iGreen = (int)round((double)m_clrFill.Green() / 1.5);
	iBlue = (int)round((double)m_clrFill.Blue() / 1.5);
	wxColour clrFill(iRed, iGreen, iBlue);
	wxBrush brushSelected(clrFill, wxBRUSHSTYLE_FDIAGONAL_HATCH);
	rDC.SetBrush(brushSelected);

	rDC.DrawPolygon(&m_Vertexes);
}
