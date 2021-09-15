/***************************************************************
 * Name:      IObject.h
 * Purpose:   Code for Object Interface
 * Author:    Юрий Зинченко (asmodeus.x5@outlook.com)
 * Created:   2018-11-30
 * Copyright: Юрий Зинченко (2018)
 * License:   GPLv3
 **************************************************************/

#include "IObject.h"

#include <string.h>
using namespace std;

IObject::IObject(const wxPointList &rVertexList,
				const wxColor &rclrBorder,
				const wxColor &rclrFill,
				const wxString &rwsName,
				const char* szClassName) :
	m_bExist(true)
{
	m_Vertexes.assign(rVertexList.begin(), rVertexList.end());
	m_clrBorder = rclrBorder;
	m_clrFill = rclrFill;
	strcpy(m_szClassName, szClassName);
	m_wsName = rwsName;
}

IObject& IObject::operator=(const IObject& rhs)
{
	if (this == &rhs)
		return *this;
	Copy(rhs);
	return *this;
}

void IObject::DrawVertexes(wxPaintDC& rDC) const
{
	for (auto it = m_Vertexes.begin(); it != m_Vertexes.end(); it++)
		DrawVertexHelper(rDC, **it);
}

void IObject::DrawVertexHelper(wxPaintDC& rDC, const wxPoint &rCoord) const
{
	const int iHelperSize = 5;
	wxColor clrBorder(0, 0, 0);
	wxColor clrFill(255, 255, 255);
	wxPen pen(clrBorder, 1);
	wxBrush brush(clrFill);
	wxRect rectVert(rCoord.x - iHelperSize, rCoord.y - iHelperSize, iHelperSize * 2, iHelperSize * 2);
	rDC.SetPen(pen);
	rDC.SetBrush(brush);
	rDC.DrawRectangle(rectVert);
}

void IObject::Copy(const IObject& r)
{
	m_clrBorder = r.m_clrBorder;
	m_clrFill = r.m_clrFill;
	m_bExist = r.m_bExist;
	m_Vertexes.assign(r.m_Vertexes.begin(), r.m_Vertexes.end());
}
