/***************************************************************
 * Name:      IShape.h
 * Purpose:   Defines Shape Interface
 * Author:    Юрий Зинченко (asmodeus.x5@outlook.com)
 * Created:   2018-11-30
 * Copyright: Юрий Зинченко (2018)
 * License:   GPLv3
 **************************************************************/

#pragma once
#ifndef ISHAPE_H
#define ISHAPE_H

#include "IObject.h"

class IShape : public IObject
{
public:
	IShape(	const wxPointList &rVertexList,
			const wxColor &rclrBorder,
			const wxColor &rclrFill,
			const wxString &rwsName,
			const char* szClassName) :
			IObject(rVertexList, rclrBorder, rclrFill, rwsName, szClassName) {};

	virtual ~IShape() {};
	IShape(const IShape& other) : IObject(other.m_Vertexes, other.m_clrBorder, other.m_clrFill, other.m_wsName, other.m_szClassName) {};
	IShape& operator=(const IShape& other);

    void Draw(wxPaintDC &rDC) const;
    void DrawAsSelected(wxPaintDC &rDC) const;
};

#endif // ISHAPE_H
