#pragma once
#include "Object.h"
#include "Bullets.h"
#include <bitset>
#include <list>

class CLevel;
class CPlayer : public CMultiObject
{
public:
	CPlayer(CLevel* pParent);
	virtual ~CPlayer();
	void Init(Vector2u vecuCoord)
	{
		m_Sprites[SPR_BOTOM]->GetSprite().setPosition(Vector2f((float)vecuCoord.x, (float)vecuCoord.y));
	}

	void Tick(UINT64 nElapsedTime);
	void DrawBullets(RenderWindow* pRenderWindow)
	{
		m_pBulletsGun->Draw(pRenderWindow);
		m_pBulletsMg->Draw(pRenderWindow);
	}
	void DrawHud(RenderWindow* pRenderWindow);
	Vector2f GetPosition() { return GetSprite(SPR_BOTOM).getPosition(); }
	Vector2f GetSize() { return (Vector2f)(GetSprite(SPR_BOTOM).getTexture()->getSize()); }

	bool IsAlive() const { return m_bIsAlive; }
	void Hit(float fDamage)
	{
		m_fHealth -= fDamage;
		if (m_fHealth <= 0.0f)
			m_bIsAlive = false;
	}

private:
	CBullets* m_pBulletsGun;
	CBullets* m_pBulletsMg;

	CLevel*	m_pParentLevel;

	void ProcKeyboard(UINT64 nElapsedTime);
	void ProcMouse(UINT64 nElapsedTime);
	void Fire(UINT8 nWpnId);

	void LoadHud();

	bitset<16> m_Keys;

	float	m_fSpeed;
	float	m_fShotSpeed;
	float	m_fShotRange;
	float	m_fShotDamage;
	float	m_fHealth;
	float	m_fArmor;

	Vector2f m_fvecMousePos;

	Color	m_clrSprColor;

	Image	m_imgHealth;
	Texture	m_texHealth;
	typedef list<Sprite> TSprites;
	typedef TSprites::iterator TSpritesIt;
	TSprites m_Health;

	Image	m_imgArmor;
	Texture	m_texArmor;
	typedef list<Sprite> TSprites;
	typedef TSprites::iterator TSpritesIt;
	TSprites m_Armor;

	enum e_Sprites
	{
		SPR_BOTOM = 0,
		SPR_TOP,
		SPR_GUN,
		SPR_CROSSHAIR
	};
	enum e_Weapons
	{
		WPN_GUN,
		WPN_MACHINE_GUN
	};

	bool m_bIsAlive;

public:
	Vector2u GetTilePosition();
	UINT32 GetTileId();

	static CPlayer* sm_pPlayer;
};