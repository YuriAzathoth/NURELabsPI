/***************************************************************
 * Name:      IObject.h
 * Purpose:   Defines Object Interface
 * Author:    Юрий Зинченко (asmodeus.x5@outlook.com)
 * Created:   2018-11-30
 * Copyright: Юрий Зинченко (2018)
 * License:   GPLv3
 **************************************************************/

#pragma once
#ifndef IOBJECT_H
#define IOBJECT_H

#include <wx/dc.h>
#include <vector>
using namespace std;

class IObject
{
public:
	IObject(const wxPointList &rVertexList,
			const wxColor &rclrBorder,
			const wxColor &rclrFill,
			const wxString &rwsName,
			const char* szClassName);
	virtual ~IObject() {};
	IObject(const IObject& other) { Copy(other); }
	IObject& operator=(const IObject& other);

    virtual void Draw(wxPaintDC &rDC) const = 0;
    virtual void DrawAsSelected(wxPaintDC &rDC) const = 0;
    void DrawVertexes(wxPaintDC &rDC) const;

    inline const wxPointList &GetVertexes() const { return m_Vertexes; }
    inline const wxColour &GetColorBorder() const { return m_clrBorder; }
    inline const wxColour &GetColorFill() const { return m_clrFill; }

    inline const wxString &GetName() const { return m_wsName; }
    inline const char* GetClassName() const { return m_szClassName; }
    inline void SetName(const wxString &rwsName) { m_wsName = rwsName; }

    inline bool IsExist() const { return m_bExist; }

protected:
	void DrawVertexHelper(wxPaintDC &rDC, const wxPoint &rCoord) const;
	virtual void Copy(const IObject& r);

	wxPointList m_Vertexes;
	wxColor m_clrBorder;
	wxColor m_clrFill;

	char m_szClassName[11];
	wxString m_wsName;

	bool m_bExist;
};

#endif // IOBJECT_H
