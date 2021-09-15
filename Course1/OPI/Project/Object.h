#pragma once
#include <list>
#include <map>
#include <vector>

class CSprite
{
public:
	CSprite(const string &sSprite);

	Sprite &GetSprite() { return m_sprSprite; }

	void SetCenterOrigin() { m_sprSprite.setOrigin(GetCenter()); }
	Vector2f GetCenter() const;

private:
	Image	m_imgSprite;
	Texture	m_texSprite;
	Sprite	m_sprSprite;
};

class CLevel;
class CObject
{
public:
	CObject(const string& sObjName);
	virtual ~CObject() {};

	virtual void Tick(UINT64 nElapsedTime) = 0;
	virtual void Draw(RenderWindow *pRenderWindow) = 0;

	void SetObjType(UINT8 nObjectType) { m_nObjectType = nObjectType; }
	UINT8 GetObjType() const { return m_nObjectType; }

	static UINT8 GetObjTypeByStr(const string &sObjType);
	enum e_ObjType
	{
		OBJTYPE_LAND,
		OBJTYPE_AIR,
		OBJTYPE_WATER,
		OBJTYPE_PROJECTILE
	};

protected:
	Rect<float> m_rcTileRect;

	UINT8 m_nObjectType;

	string m_sObjName;
};

class CSingleObject : public CObject
{
public:
	CSingleObject(const string &sSprite, const string &sObjName = "");
	virtual ~CSingleObject() {};

	virtual void Tick(UINT64 nElapsedTime) = 0;
	virtual void Draw(RenderWindow *pRenderWindow)
	{
		pRenderWindow->draw(m_sprSprite);
	}

protected:
	Image	m_imgSprite;
	Texture	m_texSprite;
	Sprite	m_sprSprite;

	void LoadSprite(const string &sSprPath, Color clrMask = Color(0, 0, 255));
	Sprite &GetSprite() { return m_sprSprite; }

	void SetCenterOrigin()
	{
		Vector2f vecfCenter;
		vecfCenter.x = (float)m_sprSprite.getTexture()->getSize().x / 2;
		vecfCenter.y =(float)m_sprSprite.getTexture()->getSize().y / 2;
		m_sprSprite.setOrigin(vecfCenter);
	}
};

class CMultiObject : public CObject
{
public:
	CMultiObject(const string &sObjName = "", UINT8 nSizeReserved = 0) : CObject(sObjName)
	{
		if (nSizeReserved)
			m_Sprites.reserve(nSizeReserved);
	};
	virtual ~CMultiObject();

	virtual void Tick(UINT64 nElapsedTime) = 0;
	virtual void Draw(RenderWindow *pRenderWindow);

protected:
	typedef vector<CSprite*> TSprites;
	typedef TSprites::iterator TSpritesIt;
	TSprites m_Sprites;

	void LoadSprite(UINT8 nId, const string &sSprPath)
	{
		m_Sprites.push_back(new CSprite(sSprPath));
	}
	Sprite &GetSprite(UINT8 nId)
	{
		return m_Sprites.at(nId)->GetSprite();
	}

	void SetCenterOrigin(UINT8 nId)
	{
		m_Sprites.at(nId)->SetCenterOrigin();
	}
};

class CObjectList : public CObject
{
public:
	CObjectList(const string &sObjName = "") : CObject(sObjName) {};
	virtual ~CObjectList();

	virtual void Tick(UINT64 nElapsedTime) = 0;
	virtual void Draw(RenderWindow *pRenderWindow);

protected:
	typedef list<CSprite*> TSprites;
	typedef TSprites::iterator TSpritesIt;
	TSprites m_Sprites;

	Sprite &LoadSprite(const string &sSprPath)
	{
		m_Sprites.push_back(new CSprite(sSprPath));
		return m_Sprites.back()->GetSprite();
	}

	void SetCenterOrigin()
	{
		m_Sprites.back()->SetCenterOrigin();
	}
};