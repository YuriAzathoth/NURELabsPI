#include "MapFormat.h"

#include <wx/xml/xml.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

MapFormat::MapFormat() :
	m_pObjMgr(NULL),
	m_szFileName(NULL),
	m_bModified(false),
	m_bNew(true)
{
	Create();
}

MapFormat::~MapFormat()
{
	if (m_szFileName)
		delete m_szFileName;
	if (m_pObjMgr)
		delete m_pObjMgr;
}

void MapFormat::Create()
{
	m_MapSettings.Bkgrnd.Red = L"255";
	m_MapSettings.Bkgrnd.Green = L"255";
	m_MapSettings.Bkgrnd.Blue = L"255";

	m_MapSettings.Scale = L"1.0";

	if (m_pObjMgr)
		delete m_pObjMgr;
	m_pObjMgr = new ObjectManager();
}

void MapFormat::Open(const char* szFileName)
{
	if (m_szFileName)
		delete m_szFileName;
	int iStrLength = strlen(szFileName);
	m_szFileName = new char[iStrLength + 1];
	strcpy(m_szFileName, szFileName);

	wxXmlDocument* doc = new wxXmlDocument();
	doc->Load(szFileName);

	wxXmlNode* child = doc->GetRoot()->GetChildren();
	while (child)
	{
		if (child->GetName() == _T("params"))
		{
			wxXmlNode* subChild = child->GetChildren();
			while (subChild)
			{
				if (subChild->GetName() == _T("bkgrnd"))
				{
					m_MapSettings.Bkgrnd.Red = subChild->GetAttribute(_T("red"), _T("255"));
					m_MapSettings.Bkgrnd.Green = subChild->GetAttribute(_T("green"), _T("255"));
					m_MapSettings.Bkgrnd.Blue = subChild->GetAttribute(_T("blue"), _T("255"));
				}
				else if (subChild->GetName() == _T("geogr"))
					m_MapSettings.Scale = subChild->GetAttribute(_T("scale"), _T("1.0"));
				subChild = subChild->GetNext();
			}
		}
		else
		{
			wxXmlNode* subChild = child->GetChildren();
			while (subChild)
			{
				if (subChild->GetName() == _T("object"))
				{
					wxPointList vertexes;
					wxXmlNode* vertex = subChild->GetChildren();
					while (vertex)
					{
						if (vertex->GetName() == _T("vertex"))
						{
							int iX = GetInt(vertex->GetAttribute(_T("x"), _T("0")));
							int iY = GetInt(vertex->GetAttribute(_T("y"), _T("0")));
							vertexes.push_back(new wxPoint(iX, iY));
						}
						vertex = vertex->GetNext();
					}
					wxString wsName = subChild->GetAttribute(_T("name"), _T("unnamed"));
					wxString wsType = child->GetName();
					if (wsType == _T("city"))
						m_pObjMgr->AddObject(vertexes, wsName, ObjectManager::CITY, true);
					else if (wsType == _T("village"))
						m_pObjMgr->AddObject(vertexes, wsName, ObjectManager::VILLAGE, true);
					else if (wsType == _T("forest"))
						m_pObjMgr->AddObject(vertexes, wsName, ObjectManager::FOREST, true);
					else if (wsType == _T("wood"))
						m_pObjMgr->AddObject(vertexes, wsName, ObjectManager::WOOD, true);
					else if (wsType == _T("sea"))
						m_pObjMgr->AddObject(vertexes, wsName, ObjectManager::SEA, true);
					else if (wsType == _T("road"))
						m_pObjMgr->AddObject(vertexes, wsName, ObjectManager::ROAD, true);
					else if (wsType == _T("rail"))
						m_pObjMgr->AddObject(vertexes, wsName, ObjectManager::RAIL, true);
					else if (wsType == _T("river"))
						m_pObjMgr->AddObject(vertexes, wsName, ObjectManager::RIVER, true);
				}
				subChild = subChild->GetNext();
			}
		}
		child = child->GetNext();
	}
	delete doc;
	m_bNew = false;
}

void MapFormat::SaveFile(const char* szFileName) const
{
	wxXmlDocument* doc = new wxXmlDocument();
	doc->SetFileEncoding("Unicode");

	wxXmlNode* nodeRoot = new wxXmlNode(wxXML_ELEMENT_NODE, _T("root"));
	doc->SetRoot(nodeRoot);
	{
		wxXmlNode* nodeParams = new wxXmlNode(nodeRoot, wxXML_ELEMENT_NODE, _T("params"));
		wxXmlNode* nodeSub;
		nodeSub = new wxXmlNode(nodeParams, wxXML_ELEMENT_NODE, _T("bkgrnd"));
		nodeSub->AddAttribute(_T("red"), m_MapSettings.Bkgrnd.Red);
		nodeSub->AddAttribute(_T("green"), m_MapSettings.Bkgrnd.Green);
		nodeSub->AddAttribute(_T("blue"), m_MapSettings.Bkgrnd.Blue);
		nodeSub = new wxXmlNode(nodeParams, wxXML_ELEMENT_NODE, _T("geogr"));
		nodeSub->AddAttribute(_T("scale"), m_MapSettings.Scale);
	}
	{
		wxXmlNode* nodeCity = new wxXmlNode(nodeRoot, wxXML_ELEMENT_NODE, _T("city"));
		wxXmlNode* nodeVillage = new wxXmlNode(nodeRoot, wxXML_ELEMENT_NODE, _T("village"));
		wxXmlNode* nodeForest = new wxXmlNode(nodeRoot, wxXML_ELEMENT_NODE, _T("forest"));
		wxXmlNode* nodeWood = new wxXmlNode(nodeRoot, wxXML_ELEMENT_NODE, _T("wood"));
		wxXmlNode* nodeSea = new wxXmlNode(nodeRoot, wxXML_ELEMENT_NODE, _T("sea"));
		wxXmlNode* nodeRoad = new wxXmlNode(nodeRoot, wxXML_ELEMENT_NODE, _T("road"));
		wxXmlNode* nodeRail = new wxXmlNode(nodeRoot, wxXML_ELEMENT_NODE, _T("rail"));
		wxXmlNode* nodeRiver = new wxXmlNode(nodeRoot, wxXML_ELEMENT_NODE, _T("river"));
		wxXmlNode* nodeObject;
		wxXmlNode* nodeVertex;

		auto rObjects = m_pObjMgr->GetObjects();
		for (auto itObj = rObjects.cbegin(); itObj != rObjects.cend(); itObj++)
		{
			const char* szType = (*itObj).second->GetClassName();

			auto rCoords = (*itObj).second->GetVertexes();
			if (!strcmp(szType, "city"))
				nodeObject = new wxXmlNode(nodeCity, wxXML_ELEMENT_NODE, _T("object"));
			else  if (!strcmp(szType, "village"))
				nodeObject = new wxXmlNode(nodeVillage, wxXML_ELEMENT_NODE, _T("object"));
			else  if (!strcmp(szType, "forest"))
				nodeObject = new wxXmlNode(nodeForest, wxXML_ELEMENT_NODE, _T("object"));
			else  if (!strcmp(szType, "wood"))
				nodeObject = new wxXmlNode(nodeWood, wxXML_ELEMENT_NODE, _T("object"));
			else  if (!strcmp(szType, "sea"))
				nodeObject = new wxXmlNode(nodeSea, wxXML_ELEMENT_NODE, _T("object"));
			else  if (!strcmp(szType, "road"))
				nodeObject = new wxXmlNode(nodeRoad, wxXML_ELEMENT_NODE, _T("object"));
			else  if (!strcmp(szType, "rail"))
				nodeObject = new wxXmlNode(nodeRail, wxXML_ELEMENT_NODE, _T("object"));
			else  if (!strcmp(szType, "river"))
				nodeObject = new wxXmlNode(nodeRiver, wxXML_ELEMENT_NODE, _T("object"));
			else
				continue;

			nodeObject->AddAttribute(_T("name"), (*itObj).first);
			for (auto itVert = rCoords.begin(); itVert != rCoords.end(); itVert++)
			{
				nodeVertex = new wxXmlNode(nodeObject, wxXML_ELEMENT_NODE, _T("vertex"));
				char cBuf[11] = "";
				nodeVertex->AddAttribute(_T("x"), itoa((*itVert)->x, cBuf, 10));
				nodeVertex->AddAttribute(_T("y"), itoa((*itVert)->y, cBuf, 10));
			}
		}
	}

	doc->Save(szFileName);
	delete doc;
}

void MapFormat::Save(const char* szFileName)
{
	SaveFile(szFileName);

	if (m_bNew)
		m_bNew = false;
	if (m_bModified)
		m_bModified = false;

	if (m_szFileName)
		delete m_szFileName;
	int iStrLength = strlen(szFileName);
	m_szFileName = new char[iStrLength + 1];
	strcpy(m_szFileName, szFileName);
}

void MapFormat::Save()
{
	SaveFile(m_szFileName);

	if (m_bNew)
		m_bNew = false;
	if (m_bModified)
		m_bModified = false;
}

int MapFormat::GetInt(wxString wsString) const
{
	char szString[11];
	strcpy(szString, wsString.c_str().AsChar());
	return atoi(szString);
}

double MapFormat::GetDouble(wxString wsString) const
{
	char szString[11];
	strcpy(szString, wsString.c_str().AsChar());
	return atof(szString);
}

wxColour MapFormat::GetBackgroundColor() const
{
	wxColour color;
	color.Set(GetInt(m_MapSettings.Bkgrnd.Red), GetInt(m_MapSettings.Bkgrnd.Green), GetInt(m_MapSettings.Bkgrnd.Blue));
	return color;
}
