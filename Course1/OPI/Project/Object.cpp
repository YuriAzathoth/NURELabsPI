#include "stdafx.h"
#include "Object.h"
#include <algorithm>


CObject::CObject(const string &sObjName) : m_nObjectType(0)
{
	m_sObjName = sObjName;
};


UINT8 CObject::GetObjTypeByStr(const string &sObjectType)
{
	if (sObjectType == "land")
		return OBJTYPE_LAND;
	else if (sObjectType == "air")
		return OBJTYPE_AIR;
	else if (sObjectType == "water")
		return OBJTYPE_WATER;
	else if (sObjectType == "projectile")
		return OBJTYPE_PROJECTILE;
	else
		return OBJTYPE_LAND;
}


CSingleObject::CSingleObject(const string &sSprite, const string &sObjName) :
	CObject(sObjName)
{
	LoadSprite(sSprite);
}


void CSingleObject::LoadSprite(const string &sSprPath, Color clrMask)
{
	m_imgSprite.loadFromFile(sSprPath);
	m_imgSprite.createMaskFromColor(Color(0, 0, 255));

	m_texSprite.loadFromImage(m_imgSprite);
	m_texSprite.setSmooth(false);

	m_sprSprite.setTexture(m_texSprite);
}


CMultiObject::~CMultiObject()
{
	while (!m_Sprites.empty())
	{
		delete m_Sprites.back();
		m_Sprites.pop_back();
	}
}


void CMultiObject::Draw(RenderWindow *pRenderWindow)
{
	for (TSpritesIt it = m_Sprites.begin(); it != m_Sprites.end(); it++)
		pRenderWindow->draw((*it)->GetSprite());
}


CObjectList::~CObjectList()
{
	while (!m_Sprites.empty())
	{
		delete m_Sprites.back();
		m_Sprites.pop_back();
	}
}


void CObjectList::Draw(RenderWindow *pRenderWindow)
{
	for (TSpritesIt it = m_Sprites.begin(); it != m_Sprites.end(); it++)
		pRenderWindow->draw((*it)->GetSprite());
}


CSprite::CSprite(const string &sSprite)
{
	m_imgSprite.loadFromFile(sSprite);
	m_imgSprite.createMaskFromColor(Color(0, 0, 255));

	m_texSprite.loadFromImage(m_imgSprite);
	m_texSprite.setSmooth(false);

	m_sprSprite.setTexture(m_texSprite);
}


Vector2f CSprite::GetCenter() const
{
	Vector2f fvecCenter;
	fvecCenter.x = (float)m_sprSprite.getTexture()->getSize().x / 2;
	fvecCenter.y = (float)m_sprSprite.getTexture()->getSize().y / 2;
	return fvecCenter;
}