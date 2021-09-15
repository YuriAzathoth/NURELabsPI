/***************************************************************
 * Name:      ISpline.h
 * Purpose:   Defines Spline Interface
 * Author:    ёрий «инченко (asmodeus.x5@outlook.com)
 * Created:   2018-12-1
 * Copyright: ёрий «инченко (2018)
 * License:   GPLv3
 **************************************************************/

#pragma once
#ifndef ISPLINE_H
#define ISPLINE_H

#include "IObject.h"

class ISpline : public IObject
{
public:
	ISpline(const wxPointList &rVertexList,
			const wxColor &rclrBorder,
			const wxColor &rclrFill,
			const wxString &rwsName,
			const char* szClassName) :
			IObject(rVertexList, rclrBorder, rclrFill, rwsName, szClassName) {};

	virtual ~ISpline() {};
	ISpline(const ISpline& other) : IObject(other.m_Vertexes, other.m_clrBorder, other.m_clrFill, other.m_wsName, other.m_szClassName) {};
	ISpline& operator=(const ISpline& other);

    void Draw(wxPaintDC &rDC) const;
    void DrawAsSelected(wxPaintDC &rDC) const;
};

#endif // ISPLINE_H
