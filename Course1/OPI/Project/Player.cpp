#include "stdafx.h"
#include "Player.h"
#include "GeomFunc.h"
#include "Level.h"


CPlayer::CPlayer(CLevel* pParent) :
	CMultiObject("Player", 2),
	m_fSpeed(1.0f),
	m_fShotSpeed(1.0f),
	m_fShotRange(800.0f),
	m_fShotDamage(1.0f),
	m_fHealth(3.0f),
	m_fArmor(2.5f),
	m_bIsAlive(true)
{
	sm_pPlayer = this;
	m_pParentLevel = pParent;

	LoadSprite(SPR_BOTOM, "tank_bottom.png");
	SetCenterOrigin(SPR_BOTOM);

	LoadSprite(SPR_TOP, "tank_top.png");
	SetCenterOrigin(SPR_TOP);

	LoadSprite(SPR_GUN, "tank_gun.png");
	SetCenterOrigin(SPR_GUN);

	m_pBulletsGun = new CBullets("Bullet_Player", m_pParentLevel);
	m_pBulletsGun->SetSpeed(2.0f);
	m_pBulletsGun->SetScale(0.6f);
	m_pBulletsGun->SetFireRate(2.5f);

	m_pBulletsMg = new CBullets("Bullet_Player", m_pParentLevel);
	m_pBulletsMg->SetSpeed(2.0f);
	m_pBulletsMg->SetScale(0.25f);
	m_pBulletsMg->SetDamage(0.08f);
	m_pBulletsMg->SetFireRate(0.5f);

	LoadSprite(SPR_CROSSHAIR, "crosshair.png");
	SetCenterOrigin(SPR_CROSSHAIR);

	LoadHud();
}


CPlayer::~CPlayer()
{
	delete m_pBulletsGun;
	delete m_pBulletsMg;
}


void CPlayer::Tick(UINT64 nElapsedTime)
{
	ProcMouse(nElapsedTime);
	ProcKeyboard(nElapsedTime);

	GetSprite(SPR_TOP).setPosition(GetSprite(SPR_BOTOM).getPosition());

	float fDx = (float)m_fvecMousePos.x - GetSprite(SPR_BOTOM).getPosition().x;
	float fDy = (float)m_fvecMousePos.y - GetSprite(SPR_BOTOM).getPosition().y;
	float fAngle = RadToDeg(atan2f(fDy, fDx)) + 90.0f;
	GetSprite(SPR_TOP).setRotation(fAngle);

	m_pBulletsGun->Tick(nElapsedTime);
	m_pBulletsMg->Tick(nElapsedTime);

	GetSprite(SPR_CROSSHAIR).rotate((float)(nElapsedTime / 100));
}


void CPlayer::ProcMouse(UINT64 nElapsedTime)
{
	if (Mouse::isButtonPressed(Mouse::Button::Left))
		Fire(WPN_GUN);

	if (Mouse::isButtonPressed(Mouse::Button::Right))
		Fire(WPN_MACHINE_GUN);
}


CLevel::TTileIdCoord CPlayer::GetTilePosition()
{
	return m_pParentLevel->CoordToTileIdCoord(GetPosition());
}


CLevel::TTileId CPlayer::GetTileId()
{
	return m_pParentLevel->CoordToTileId(GetPosition());
}


void CPlayer::ProcKeyboard(UINT64 nElapsedTime)
{
	float fDx = 0.0f;
	float fDy = 0.0f;
	float fX = 0.0f;
	float fY = 0.0f;
	bool bMustMove = false;
	bool bCanMove = true;

	CLevel::TTileIdCoord tcCurrTile = m_pParentLevel->CoordToTileIdCoord(GetPosition());
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		fY = -1;
		bMustMove = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		fY = 1;
		bMustMove = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		fX = -1;
		bMustMove = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		fX = 1;
		bMustMove = true;
	}

	// Collision
	if (fX || fY)
	{
		CLevel::TTileIdCoord tcCurrTile = m_pParentLevel->CoordToTileIdCoord(GetPosition());
		tcCurrTile.x += (INT8)fX;
		tcCurrTile.y += (INT8)fY;

		for (int i = 0; i < m_pParentLevel->GetLayerCount(); i++)
		{
			UINT8 nTileType = m_pParentLevel->GetTileType(0, m_pParentLevel->TileIdCoordToTileId(tcCurrTile));
			if (m_nObjectType == OBJTYPE_LAND)
			{
				if ((nTileType == CLevel::TYPE_BLOCK)
					|| (nTileType == CLevel::TYPE_TREE)
					|| (nTileType == CLevel::TYPE_WALL)
					|| (nTileType == CLevel::TYPE_VOID)
					|| (nTileType == CLevel::TYPE_WATER))
					bCanMove = false;
			}
		}
	}

	if (bMustMove && bCanMove)
	{
		float fAngle = atan2f(fX, fY);
		GetSprite(SPR_BOTOM).setRotation(RadToDeg(atan2f(fX, -fY)));

		float fDl = m_fSpeed * (float)((double)nElapsedTime / 1000.0);
		float fDx = fDl * sin(fAngle);
		float fDy = fDl * cos(fAngle);
		GetSprite(SPR_BOTOM).move(fDx, fDy);
	}
}


void CPlayer::Fire(UINT8 nWpnId)
{
	Sprite &rsprPlayer = m_Sprites.at(SPR_TOP)->GetSprite();
	switch (nWpnId)
	{
	case WPN_GUN:
		m_pBulletsGun->Fire(rsprPlayer.getRotation() - 90.0f, rsprPlayer.getPosition());
		break;
	case WPN_MACHINE_GUN:
		m_pBulletsMg->Fire(rsprPlayer.getRotation() - 90.0f, rsprPlayer.getPosition());
		break;
	}
}


void CPlayer::LoadHud()
{
	m_imgHealth.loadFromFile("heart.png");
	m_imgHealth.createMaskFromColor(Color(0, 0, 255));
	m_texHealth.loadFromImage(m_imgHealth);

	m_imgArmor.loadFromFile("armor.png");
	m_imgArmor.createMaskFromColor(Color(0, 0, 255));
	m_texArmor.loadFromImage(m_imgArmor);
}


void CPlayer::DrawHud(RenderWindow* pRenderWindow)
{
	m_fvecMousePos.x = (float)(Mouse::getPosition().x);
	m_fvecMousePos.y = (float)(Mouse::getPosition().y);
	GetSprite(SPR_CROSSHAIR).setPosition(m_fvecMousePos);

	Sprite* pCurrSprite = NULL;

	if (m_fHealth > 0)
	{
		for (int i = 0; (int)m_fHealth + 1 != (int)m_Health.size(); i++)
		{
			if ((int)m_fHealth + 1 > (int)m_Health.size())
			{
				m_Health.push_back(Sprite());
				pCurrSprite = &m_Health.back();
				pCurrSprite->setTexture(m_texHealth);
				pCurrSprite->setPosition(16 + (float)(pCurrSprite->getTexture()->getSize().x + 2) * (i + 1), 16);
			}
			else if ((int)m_fHealth + 1 < (int)m_Health.size())
			{
				m_Health.pop_back();
			}
		}
		pCurrSprite = &m_Health.back();
		pCurrSprite->setTextureRect(IntRect(0, 0, (int)((float)pCurrSprite->getTexture()->getSize().x * (m_fHealth - (float)(int)m_fHealth)), pCurrSprite->getTexture()->getSize().y));
		if (!m_Armor.empty())
		{
			for (TSpritesIt it = m_Health.begin(); it != m_Health.end(); it++)
				pRenderWindow->draw(*it);
		}
	}
	else
		m_fArmor = 0.0f;

	if (m_fArmor > 0)
	{
		for (int i = 0; (int)m_fArmor + 1 != (int)m_Armor.size(); i++)
		{
			if ((int)m_fArmor + 1 > (int)m_Armor.size())
			{
				m_Armor.push_back(Sprite());
				pCurrSprite = &m_Armor.back();
				pCurrSprite->setTexture(m_texArmor);
				pCurrSprite->setPosition(16 + (float)(pCurrSprite->getTexture()->getSize().x + 2) * (i + m_fHealth + 1), 16);
			}
			else if ((int)m_fArmor + 1 < (int)m_Armor.size())
			{
				m_Armor.pop_back();
			}
		}
		pCurrSprite = &m_Armor.back();
		pCurrSprite->setTextureRect(IntRect(0, 0, (int)((float)pCurrSprite->getTexture()->getSize().x * (m_fArmor - (float)(int)m_fArmor)), pCurrSprite->getTexture()->getSize().y));
		if (!m_Armor.empty())
		{
			int i = 0;
			for (TSpritesIt it = m_Armor.begin(); it != m_Armor.end(); it++, i++)
			{
				(*it).setPosition(16 + (float)(pCurrSprite->getTexture()->getSize().x + 2) * (i + (int)(m_fHealth + 0.9f) + 1), 16);
				pRenderWindow->draw(*it);
			}
		}
	}
	else
		m_fArmor = 0.0f;
}


CPlayer* CPlayer::sm_pPlayer = NULL;