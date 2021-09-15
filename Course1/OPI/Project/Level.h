#pragma once
#include "Player.h"
#include <vector>
#include <map>
#include <list>
#include "Enemy.h"


class CLevel
{
public:
	CLevel(Vector2u vecuWndSize);
	~CLevel();

	bool LoadFromFile(const string &sFileName);

	void Tick(UINT64 nElapsedTime);
	void Draw(RenderWindow *pRenderWindow);

	typedef UINT32		TTileId;
	typedef Vector2u	TTileIdCoord;

	typedef TTileId		TTileIdType;
	typedef UINT32		TTileIdCoordType;

	typedef float		TCoordType;
	typedef Vector2<TCoordType>	TCoord;

	UINT8 GetTypeByStr(const string &sType);
	UINT8 GetTileType(UINT8 nLayerId, TTileId nTileId)
	{
		return m_Layers[nLayerId].GetTile(nTileId/* - m_nFirstTileId*/).GetTileType();
	}
	UINT8 GetTileTypeByCoord(UINT8 nLayerId, TCoord vecfCoord)
	{
		return GetTileType(nLayerId, CoordToTileId(vecfCoord));
	}
	enum e_TileType
	{
		TYPE_NONE,
		TYPE_FIELD,
		TYPE_BLOCK,
		TYPE_WATER,
		TYPE_TREE,
		TYPE_WALL,
		TYPE_MUD,
		TYPE_VOID
	};

	TTileIdCoord TileIdToTileIdCoord(TTileId tiId) const
	{
		TTileIdCoord tcTile;
		tcTile.x = tiId % m_nMapWidth;
		tcTile.y = (UINT16)(tiId / m_nMapWidth);
		return tcTile;
	}
	TTileId TileIdCoordToTileId(TTileIdCoord tcCoord) const
	{
		return tcCoord.y * m_nMapWidth + tcCoord.x;
	}
	TTileIdCoord CoordToTileIdCoord(TCoord vecfCoord) const
	{
		TTileIdCoord tiCoord;
		tiCoord.x = (TTileIdType)(vecfCoord.x / m_nTileWidth);
		tiCoord.y = (TTileIdType)(vecfCoord.y / m_nTileHeight);
		return tiCoord;
	}
	TTileIdCoord CoordToTileIdCoord(Vector2u vecuCoord) const
	{
		return CoordToTileIdCoord((TCoord)vecuCoord);
	}
	TCoord TileIdCoordToCoord(TTileIdCoord tiCoord) const
	{
		TCoord vecfCoord;
		vecfCoord.x = (TCoordType)(tiCoord.x * m_nTileWidth);
		vecfCoord.y = (TCoordType)(tiCoord.y * m_nTileHeight);
		return vecfCoord;
	}
	TTileId CoordToTileId(TCoord vecfCoord) const
	{
		return TileIdCoordToTileId(CoordToTileIdCoord(vecfCoord));
	}
	TTileId CoordToTileId(Vector2u vecuCoord) const
	{
		return CoordToTileId((TCoord)vecuCoord);
	}

	UINT8 GetTileIdOffset() const { return m_nFirstTileId; }

	Vector2u GetTileSize() const
	{
		Vector2u vecuTileSize(m_nTileWidth, m_nTileHeight);
		return vecuTileSize;
	}
	Vector2u GetMapSize() const
	{
		Vector2u vecuMapSize;
		vecuMapSize.x = m_nMapWidth * m_nTileWidth;
		vecuMapSize.y = m_nMapHeight * m_nTileHeight;
		return vecuMapSize;
	}

	CPlayer* GetPlayer() { return m_pPlayer; }
	Vector2f GetPlayerPosition() const { return m_pPlayer->GetPosition(); }

	UINT8 GetLayerCount() const { return m_Layers.size(); }

	bool IsErrorOccured() const { return m_bErrorState; }

	Vector2u GetWndSize() const { return m_vecuWndSize; }

	list<CEnemy*> &GetEnemyList() { return m_Enemies; }

	void AddScore(UINT32 nScore) { m_nScore; }
	UINT32 GetScore() const { return m_nScore; }

private:
	CPlayer*	m_pPlayer;

	UINT8	m_nMapWidth;
	UINT8	m_nMapHeight;
	UINT8	m_nTileWidth;
	UINT8	m_nTileHeight;
	UINT8	m_nFirstTileId;

	bool	LoadTileset(const string &sFileName);

	Image	m_imgTileset;
	Texture	m_texTileset;

	bool	m_bErrorState;

	typedef map<UINT16, UINT8> TTileTypes;
	TTileTypes m_TileTypes;

	class CLayer
	{
	private:
		class CTile;
	public:
		void Reserve(UINT32 nMapSize) { m_Tiles.reserve(nMapSize); }
		void PushTile(const Sprite &rSprite, UINT8 nTileType)
		{
			m_Tiles.push_back(CTile(rSprite, nTileType));
		}

		void SetOpacity(UINT8 nOpacity) { m_nOpacity = nOpacity; }
		UINT8 GetOpacity() const { return m_nOpacity; }

		UINT16 GetVecSize() const { return m_Tiles.size(); }
		Sprite &GetTileSprite(UINT16 nTileId) { return m_Tiles[nTileId].GetTile(); }
		CTile &GetTile(UINT16 nTileId) { return m_Tiles[nTileId]; }
		CTile &GetTile(float fPosX, float fPosY, UINT16 nMapHeight)
		{
			return GetTile((UINT16)(fPosX * fPosY * (float)nMapHeight));
		}
		CTile &GetLastPushedTile() { return m_Tiles.back(); }

	private:
		UINT8	m_nOpacity;

		class CTile
		{
		public:
			CTile(const Sprite &rSprite, UINT8 nTileType)
			{
				m_sprSprite = rSprite;
				m_nTileType = nTileType;
			}
			Sprite &GetTile() { return m_sprSprite; }
			UINT8 GetTileType() const { return m_nTileType; }
		private:
			Sprite	m_sprSprite;
			UINT8	m_nTileType;
		};
		vector<CTile> m_Tiles;
	};

	typedef vector<CLayer> TLayers;
	typedef TLayers::iterator TLayersIt;
	TLayers m_Layers;

	typedef vector<Sprite> TSprites;
	TSprites m_Sprites;

	typedef map<string, string> TParams;
	typedef TParams TObject;
	typedef map<string, TParams> TObjects;
	TObjects m_Objects;

	Vector2u m_vecuWndSize;

	Rect<UINT32> m_Spawn1;
	Rect<UINT32> m_Spawn2;

	list<CEnemy*> m_Enemies;

	Font m_fntScore;
	Text m_txtScore;
	UINT32 m_nScore;
};