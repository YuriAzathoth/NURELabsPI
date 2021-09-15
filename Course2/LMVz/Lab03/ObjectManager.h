/***************************************************************
 * Name:      ObjectManager.h
 * Purpose:   Defines Object Manager
 * Author:    Юрий Зинченко (asmodeus.x5@outlook.com)
 * Created:   2018-11-30
 * Copyright: Юрий Зинченко (2018)
 * License:   GPLv3
 **************************************************************/

#pragma once
#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <wx/dc.h>
#include <map>
using namespace std;

#include "IObject.h"

class ObjectManager
{
public:
	ObjectManager() : m_pSelObj(NULL) {};
	~ObjectManager();

	enum EOBJTYPE
	{
		CITY,
		VILLAGE,
		FOREST,
		WOOD,
		SEA,
		ROAD,
		RAIL,
		RIVER
	};

	void Draw(wxPaintDC &rDC) const;
	void CheckExistence();

	void AddObject(const wxPointList &rVertexList, const wxString &rwsName, int iObjType, bool bInstantAdd = false);

	inline void Rename(const wxString &rwsNewName)
	{
		if (m_pSelObj)
			m_pSelObj->SetName(rwsNewName);
	}
	inline void Remove()
	{
		if (m_pSelObj)
		{
			delete m_pSelObj;
			m_pSelObj = NULL;
		}
	}
	inline void Select(const wxString &rwsName)
	{
		m_pSelObj = m_Objects[rwsName];
		m_Objects.erase(rwsName);
	}
	inline bool Deselect()
	{
		if (!m_pSelObj)
			return false;
		m_Objects[m_pSelObj->GetName()] = m_pSelObj;
		m_pSelObj = NULL;
		return true;
	}

	typedef map<wxString, IObject*> TObjects;
	const TObjects &GetObjects() const { return m_Objects; }
	IObject* GetObjectByName(const wxString &wsName) { return m_Objects[wsName]; }
	IObject* GetObjectSelected() const { return m_pSelObj; }

private:
	TObjects m_Objects;
	IObject* m_pSelObj;

	ObjectManager(const ObjectManager&) = delete;
	ObjectManager& operator=(const ObjectManager&) = delete;
};

#endif // OBJECTMANAGER_H
