#pragma once
#ifndef MAPFORMAT_H
#define MAPFORMAT_H

#include <wx/colour.h>
#include <wx/string.h>

#include "ObjectManager.h"

class MapFormat
{
public:
	MapFormat();
	~MapFormat();
	void Create();
	void Open(const char* szFileName);
	void Save();
	void Save(const char* szFileName);

	const char* GetFileName() const { return m_szFileName; }
	bool IsModified() const { return m_bModified; }
	bool IsNew() const { return m_bNew; }

	ObjectManager* GetObjectManager() const { return m_pObjMgr; }

    int GetInt(wxString wsString) const;
    double GetDouble(wxString wsString) const;
	wxColor GetBackgroundColor() const;

	void Draw(wxPaintDC &rDC) { m_pObjMgr->Draw(rDC); }

private:
	inline void SaveFile(const char* szFileName) const;

	ObjectManager* m_pObjMgr;

	struct SMapSettings
	{
		struct SColor
		{
			wxString Red;
			wxString Green;
			wxString Blue;
		};
        SColor Bkgrnd;
        wxString Scale;
	} m_MapSettings;

	char* m_szFileName;
	bool m_bModified;
	bool m_bNew;
};

#endif // MAPFORMAT_H
