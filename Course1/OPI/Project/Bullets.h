#pragma once
#include "Object.h"


class CProjectile : public CSprite
{
public:
	CProjectile(const string &sSprite) : CSprite(sSprite), m_fPathDone(0.0f) {};
	float GetPathDone() { return m_fPathDone; }
	void IncPathDone(float fAdd) { m_fPathDone += fAdd; }

private:
	float m_fPathDone;
};

class CEnemy;
class CLevel;
class CBullets : public CObjectList
{
public:
	CBullets(string sObjName, CLevel* pParent);

	void Tick(UINT64 nElapsedTime);
	void Fire(float fAngle, Vector2f vPosf, float fStartDist = 32.0f);

	Sprite &LoadSprite(const string &sSprPath)
	{
		m_Sprites.push_back(new CProjectile(sSprPath));
		return m_Sprites.back()->GetSprite();
	}

	bool CheckCollision(const Sprite& sprSprite);

	void SetSpeed(float fSpeed) { m_fSpeed = fSpeed; }
	void SetRange(float fRange) { m_fRange = fRange; }
	void SetDamage(float fDamage) { m_fDamage = fDamage; }
	void SetScale(float fScale) { m_fScale = fScale; }
	void SetFireRate(float fFireRate)
	{
		m_fFireRate = fFireRate;
		m_nDelay = (UINT64)(m_fFireRate * 25000.0f);
	}

protected:
	float m_fSpeed;
	float m_fRange;
	float m_fDamage;
	float m_fScale;
	float m_fFireRate;

	UINT64 m_nShotsTimer;
	UINT64 m_nDelay;

	CLevel* m_pParentLevel;
};