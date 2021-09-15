#include "stdafx.h"
#include "Level.h"
#include <tinyxml2.h>
#include <cstring>

using namespace tinyxml2;

CLevel::CLevel(Vector2u vecuWndSize) :
	m_nMapWidth(0),
	m_nMapHeight(0),
	m_nTileWidth(0),
	m_nTileHeight(0),
	m_bErrorState(false),
	m_pPlayer(NULL),
	m_nScore(0)
{
	m_pPlayer	= new CPlayer(this);

	LoadFromFile("TestMap.xml");
	m_vecuWndSize = vecuWndSize;

	m_fntScore.loadFromFile("maturasc.ttf");

	m_txtScore.setFont(m_fntScore);
	m_txtScore.setCharacterSize(16);
	m_txtScore.setPosition(256.0f, 8.0f);
	m_txtScore.setOutlineColor(Color::Black);
	m_txtScore.setFillColor(Color::White);
}


CLevel::~CLevel()
{
	delete m_pPlayer;
	while (!m_Enemies.empty())
	{
		delete m_Enemies.back();
		m_Enemies.pop_back();
	}
}


void CLevel::Tick(UINT64 nElapsedTime)
{
	if (m_pPlayer)
		m_pPlayer->Tick(nElapsedTime);
	else
	{
		MessageBoxA(NULL, "Map Error", "Player data on this map does not exist!\nPlayer spawn must be configured on the map!", MB_OK | MB_ICONEXCLAMATION);
		m_bErrorState = true;
	}

	if (m_Enemies.size() < 4)
	{
		Vector2f vecfEnemyPos;
		if (rand() % 2)
		{
			vecfEnemyPos.x = (float)(rand() % m_Spawn1.width + m_Spawn1.left);
			vecfEnemyPos.y = (float)(rand() % m_Spawn1.height + m_Spawn1.top);
		}
		else
		{
			vecfEnemyPos.x = (float)(rand() % m_Spawn2.width + m_Spawn2.left);
			vecfEnemyPos.y = (float)(rand() % m_Spawn2.height + m_Spawn2.top);
		}
		CEnemy* pEnemy = new CEnemy(vecfEnemyPos, this);
		m_Enemies.push_back(pEnemy);
	}
	for (list<CEnemy*>::iterator it = m_Enemies.begin(); it != m_Enemies.end();)
	{
		if (!(*it)->IsDead())
		{
			(*it)->Tick(nElapsedTime);
			it++;
		}
		else
		{
			delete *it;
			it = m_Enemies.erase(it);
		}
	}

	char cBuff[25];
	string strScore = itoa(m_nScore, cBuff, 10);
}


void CLevel::Draw(RenderWindow *pRenderWindow)
{
	for (TLayersIt itLayer = m_Layers.begin(); itLayer != m_Layers.end(); itLayer++)
	{
		for (int nTile = 0; nTile < (*itLayer).GetVecSize(); nTile++)
		{
			pRenderWindow->draw((*itLayer).GetTileSprite(nTile));
		}
	}

	for (list<CEnemy*>::iterator it = m_Enemies.begin(); it != m_Enemies.end(); it++)
	{
		(*it)->Draw(pRenderWindow);
	}

	m_pPlayer->Draw(pRenderWindow);
	m_pPlayer->DrawBullets(pRenderWindow);
	m_pPlayer->DrawHud(pRenderWindow);
	pRenderWindow->draw(m_txtScore);
}


bool CLevel::LoadFromFile(const string& sFileName)
{
	XMLDocument xmlLevelFile;

	UINT8 nFileLoadCode = xmlLevelFile.LoadFile(sFileName.c_str());
	if (nFileLoadCode != XML_SUCCESS)
	{
		MessageBoxA(NULL, string("Failed to load map " + sFileName + "!").c_str(), "Map loading error", MB_OK | MB_ICONERROR);
		return false;
	}

	XMLElement* xmlMap = xmlLevelFile.FirstChildElement("map");

	m_nMapWidth		= atoi(xmlMap->Attribute("width"));
	m_nMapHeight	= atoi(xmlMap->Attribute("height"));
	m_nTileWidth	= atoi(xmlMap->Attribute("tilewidth"));
	m_nTileHeight	= atoi(xmlMap->Attribute("tileheight"));

	XMLElement* xmlTileset = xmlMap->FirstChildElement("tileset");
	m_nFirstTileId = atoi(xmlTileset->Attribute("firstgid"));

	string sTilesetPath;
	if (xmlTileset->Attribute("source"))
		sTilesetPath = xmlTileset->Attribute("source");
	else
	{
		MessageBoxA(NULL, string("No layers found in map " + sFileName).c_str(), "Bad map", MB_OK | MB_ICONEXCLAMATION);
		return false;
	}

	if (!LoadTileset(sTilesetPath))
		return false;

	UINT8 nColumns	= m_texTileset.getSize().x / m_nTileWidth;
	UINT8 nRows		= m_texTileset.getSize().y / m_nTileHeight;

	typedef Rect<int> TTilesetRect;
	vector<TTilesetRect> vecSubRects;

	for (int y = 0; y < nRows; y++)
	{
		for (int x = 0; x < nColumns; x++)
		{
			Rect<int> rcRect;

			rcRect.top		= y * m_nTileHeight;
			rcRect.height	= m_nTileHeight;
			rcRect.left		= x * m_nTileWidth;
			rcRect.width	= m_nTileWidth;

			vecSubRects.push_back(rcRect);
		}
	}

	XMLElement* xmlLayer = xmlMap->FirstChildElement("layer");
	if (!xmlLayer)
	{
		MessageBoxA(NULL, string("No layers found in map " + sFileName).c_str(), "Bad map", MB_OK | MB_ICONEXCLAMATION);
		return false;
	}
	while (xmlLayer)
	{
		CLayer Layer;
		Layer.Reserve(m_nMapWidth * m_nMapHeight);

		if (xmlLayer->Attribute("opacity") != NULL)
		{
			float fOpacity = strtof(xmlLayer->Attribute("opacity"), NULL);
			Layer.SetOpacity((UINT8)(fOpacity * 255.0f));
		}
		else
			Layer.SetOpacity(255);

		XMLElement* xmlLayerData = xmlLayer->FirstChildElement("data");
		if (!xmlLayerData)
			MessageBoxA(NULL, string("No layer information found in map " + sFileName).c_str(), "Bad map", MB_OK | MB_ICONWARNING);

		XMLElement* xmlTile = xmlLayerData->FirstChildElement("tile");
		if (!xmlTile)
		{
			MessageBoxA(NULL, string("No tile information found in map " + sFileName).c_str(), "Bad map", MB_OK | MB_ICONEXCLAMATION);
			return false;
		}

		UINT32 nX = 0;
		UINT32 nY = 0;

		while (xmlTile)
		{
			UINT16 nSubRectToUse = 0;
			if (xmlTile->Attribute("gid") != NULL)
			{
				UINT16 nTileGid = atoi(xmlTile->Attribute("gid"));
				nSubRectToUse = nTileGid - m_nFirstTileId;

				if (nSubRectToUse >= 0)
				{
					Sprite sprTile;
					sprTile.setTexture(m_texTileset);
					sprTile.setTextureRect(vecSubRects[nSubRectToUse]);
					sprTile.setPosition((float)(nX * m_nTileWidth), (float)(nY * m_nTileHeight));
					sprTile.setColor(Color(255, 255, 255, Layer.GetOpacity()));

					Layer.PushTile(sprTile, m_TileTypes[nTileGid - m_nFirstTileId]);
				}
			}
			else
			{
				Sprite sprTile;
				sprTile.setPosition((float)(nX * m_nTileWidth), (float)(nY * m_nTileHeight)); // Void sprite
				Layer.PushTile(sprTile, TYPE_NONE);
			}

			xmlTile = xmlTile->NextSiblingElement("tile");

			nX++;
			if (nX >= m_nMapWidth)
			{
				nX = 0;
				nY++;
				if (nY >= m_nMapHeight)
					nY = 0;
			}
		}

		m_Layers.push_back(Layer);

		xmlLayer = xmlLayer->NextSiblingElement("layer");
	}

	XMLElement* xmlObjectGroup;
	if (xmlMap->FirstChildElement("objectgroup") != NULL)
	{
		xmlObjectGroup = xmlMap->FirstChildElement("objectgroup");
		while (xmlObjectGroup)
		{
			XMLElement *xmlObject = xmlObjectGroup->FirstChildElement("object");
			while (xmlObject)
			{
				string sObjectType;
				if (xmlObject->Attribute("type") != NULL)
					sObjectType = xmlObject->Attribute("type");

				string sObjectName;
				if (xmlObject->Attribute("name") != NULL)
					sObjectName = xmlObject->Attribute("name");

				UINT16 nX = atoi(xmlObject->Attribute("x"));
				UINT16 nY = atoi(xmlObject->Attribute("y"));

				UINT16 nWidth, nHeight;

				UINT8 nAngle = 0;
				if (xmlObject->Attribute("rotation"))
					nAngle = atoi(xmlObject->Attribute("rotation"));

				Sprite sprObject;
				sprObject.setTexture(m_texTileset);
				sprObject.setTextureRect(TTilesetRect(0, 0, 0, 0));
				sprObject.setPosition(nX, nY);

				if (xmlObject->Attribute("width") != NULL && xmlObject->Attribute("height") != NULL)
				{
					nWidth	= atoi(xmlObject->Attribute("width"));
					nHeight	= atoi(xmlObject->Attribute("height"));
				}
				else
				{
					if (xmlObject->Attribute("gid"))
					{
						TTilesetRect &rrcRectById = vecSubRects[atoi(xmlObject->Attribute("gid"))];
						nWidth = rrcRectById.width;
						nHeight = rrcRectById.height;
						sprObject.setTextureRect(vecSubRects[atoi(xmlObject->Attribute("gid") - m_nFirstTileId)]);
					}
				}

				if (sObjectName == "player")
				{
					m_pPlayer->Init(Vector2u(nX, nY));
					if (sObjectType != "")
						m_pPlayer->SetObjType(CObject::GetObjTypeByStr(sObjectType));
					else
						m_pPlayer->SetObjType(0);
				}
				else if (sObjectName == "spawn1")
				{
					m_Spawn1.left = nX;
					m_Spawn1.top = nY;
					m_Spawn1.width = atoi(xmlObject->Attribute("width"));
					m_Spawn1.height = atoi(xmlObject->Attribute("height"));
				}
				else if (sObjectName == "spawn2")
				{
					m_Spawn2.left = nX;
					m_Spawn2.top = nY;
					m_Spawn2.width = atoi(xmlObject->Attribute("width"));
					m_Spawn2.height = atoi(xmlObject->Attribute("height"));
				}

				xmlObject = xmlObject->NextSiblingElement("object");
			}
			xmlObjectGroup = xmlObjectGroup->NextSiblingElement("objectgroup");
		}
	}

	return true;
}


bool CLevel::LoadTileset(const string &sFileName)
{
	XMLDocument xmlTilesetData;

	UINT8 nFileLoadCode = xmlTilesetData.LoadFile(sFileName.c_str());
	if (nFileLoadCode != XML_SUCCESS)
	{
		MessageBoxA(NULL, (string("Failed to load tileset data ") + sFileName).c_str(), "Bad tileset data", MB_OK | MB_ICONERROR);
		return false;
	}

	XMLElement* xmlTileset = xmlTilesetData.FirstChildElement("tileset");
	if (!xmlTileset)
	{
		MessageBoxA(NULL, string("No tileset information found in tileset " + sFileName).c_str(), "Bad tileset", MB_OK | MB_ICONEXCLAMATION);
		return false;
	}

	UINT16 nTilesCount;
	if (xmlTileset->Attribute("tilecount") != NULL)
		nTilesCount = atoi(xmlTileset->Attribute("tilecount"));
	else
	{
		MessageBoxA(NULL, string("No tile count information found in tileset " + sFileName).c_str(), "Bad tileset", MB_OK | MB_ICONEXCLAMATION);
		return false;
	}

	XMLElement* xmlImage = xmlTileset->FirstChildElement("image");
	if (!xmlImage)
	{
		MessageBoxA(NULL, string("No image information found in tileset " + sFileName).c_str(), "Bad tileset", MB_OK | MB_ICONEXCLAMATION);
		return false;
	}

	string sImageName;
	if (xmlImage->Attribute("source"))
		sImageName = xmlImage->Attribute("source");
	else
	{
		MessageBoxA(NULL, string("No source image information found in tileset " + sFileName).c_str(), "Bad tileset", MB_OK | MB_ICONEXCLAMATION);
		return false;
	}

	if (!m_imgTileset.loadFromFile(sImageName))
	{
		MessageBoxA(NULL, string("Failed to load tileset source image " + sImageName + "!").c_str(), "Tileset image loading error", MB_OK | MB_ICONERROR);
		return false;
	}
	m_imgTileset.createMaskFromColor(Color(255, 255, 255));
	m_texTileset.loadFromImage(m_imgTileset);
	m_texTileset.setSmooth(false);

	XMLElement* xmlTile = xmlTileset->FirstChildElement("tile");
	if (!xmlTile)
	{
		MessageBoxA(NULL, string("No tiles information found in tileset " + sFileName).c_str(), "Bad tileset", MB_OK | MB_ICONWARNING);
		return false;
	}

	string sTileType;
	while (xmlTile)
	{
		UINT16 nCurrTileId = atoi(xmlTile->Attribute("id"));

		if (xmlTile->Attribute("type"))
		{
			string sTileType = xmlTile->Attribute("type");
			m_TileTypes.insert(pair<UINT16, UINT8>(nCurrTileId, GetTypeByStr(sTileType)));
		}
		else
			m_TileTypes.insert(pair<UINT16, UINT8>(nCurrTileId, TYPE_NONE));

		xmlTile = xmlTile->NextSiblingElement("tile");
	}

	return true;
}


UINT8 CLevel::GetTypeByStr(const string &sType)
{
	if (sType == "field")
		return TYPE_FIELD;
	else if (sType == "block")
		return TYPE_BLOCK;
	else if (sType == "water")
		return TYPE_WATER;
	else if (sType == "mud")
		return TYPE_MUD;
	else if (sType == "tree")
		return TYPE_TREE;
	else if (sType == "wall")
		return TYPE_WALL;
	else if (sType == "void")
		return TYPE_VOID;
	else
		return TYPE_NONE;
}