/***************************************************************
 * Name:      ObjectManager.cpp
 * Purpose:   Code for Object Manager
 * Author:    Юрий Зинченко (asmodeus.x5@outlook.com)
 * Created:   2018-11-30
 * Copyright: Юрий Зинченко (2018)
 * License:   GPLv3
 **************************************************************/

#include "ObjectManager.h"
#include "City.h"

#include <wx/region.h>
#include <math.h>
using namespace std;

ObjectManager::~ObjectManager()
{
	if (m_pSelObj)
	{
		delete m_pSelObj;
		m_pSelObj = NULL;
	}
	for (auto it = m_Objects.begin(); it != m_Objects.end(); it++)
        delete (*it).second;
	m_Objects.clear();
}

void ObjectManager::Draw(wxPaintDC& rDC) const
{
	for (auto it = m_Objects.cbegin(); it != m_Objects.cend(); it++)
#ifdef _DEBUG
	{
		if ((*it).first != (*it).second->GetName())
			cerr << (*it).first << " <> " << (*it).second->GetName() << endl;
#endif
		(*it).second->Draw(rDC);
#ifdef _DEBUG
	}
#endif
	if (m_pSelObj)
	{
		m_pSelObj->DrawAsSelected(rDC);
		m_pSelObj->DrawVertexes(rDC);
	}
}

void ObjectManager::CheckExistence()
{
	for (auto it = m_Objects.begin(); it != m_Objects.end(); )
		if ((*it).second->IsExist())
			it++;
		else
		{
			delete (*it).second;
            it = m_Objects.erase(it);
		}
}

void ObjectManager::AddObject(const wxPointList& rVertexList, const wxString& rwsName, int iObjType, bool bInstantAdd)
{
	if (bInstantAdd)
		switch (iObjType)
		{
		case CITY:
			m_Objects[rwsName] = new City(rVertexList, rwsName);
			break;
		case VILLAGE:
			m_Objects[rwsName] = new Village(rVertexList, rwsName);
			break;
		case FOREST:
			m_Objects[rwsName] = new Forest(rVertexList, rwsName);
			break;
		case WOOD:
			m_Objects[rwsName] = new Wood(rVertexList, rwsName);
			break;
		case SEA:
			m_Objects[rwsName] = new Sea(rVertexList, rwsName);
			break;
		case ROAD:
			m_Objects[rwsName] = new Road(rVertexList, rwsName);
			break;
		case RAIL:
			m_Objects[rwsName] = new Rail(rVertexList, rwsName);
			break;
		case RIVER:
			m_Objects[rwsName] = new River(rVertexList, rwsName);
			break;
		}
	else
		switch (iObjType)
		{
		case CITY:
			m_pSelObj = new City(rVertexList, rwsName);
			break;
		case VILLAGE:
			m_pSelObj = new Village(rVertexList, rwsName);
			break;
		case FOREST:
			m_pSelObj = new Forest(rVertexList, rwsName);
			break;
		case WOOD:
			m_pSelObj = new Wood(rVertexList, rwsName);
			break;
		case SEA:
			m_pSelObj = new Sea(rVertexList, rwsName);
			break;
		case ROAD:
			m_pSelObj = new Road(rVertexList, rwsName);
			break;
		case RAIL:
			m_pSelObj = new Rail(rVertexList, rwsName);
			break;
		case RIVER:
			m_pSelObj = new River(rVertexList, rwsName);
			break;
		}
}
