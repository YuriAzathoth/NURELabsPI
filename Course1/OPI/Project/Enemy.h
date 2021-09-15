#pragma once
#include "Object.h"
#include "Bullets.h"

class CLevel;
class CEnemy : public CMultiObject
{
public:
	CEnemy(Vector2f vecfPos, CLevel* pParentLevel);
	~CEnemy();
	void Draw(RenderWindow* pRenderWindow)
	{
		m_Bullet.Draw(pRenderWindow);
		CMultiObject::Draw(pRenderWindow);
	}
	void Tick(UINT64 nElapsedTime);

	Vector2f GetPosition() const { return m_Sprites[0]->GetSprite().getPosition(); }
	Vector2f GetSize() const { return (Vector2f)(m_Sprites[0]->GetSprite().getTexture()->getSize()); }

	void Fire();


	void Hit(float fDamage)
	{
		m_fHealth -= fDamage;
		if (m_fHealth <= 0)
			m_bIsDead = true;
	}
	bool IsDead() const { return m_bIsDead; }

private:
	Vector2f m_vecfDistance;

	float m_fHealth;
	bool m_bIsDead;

	CLevel* m_pParentLevel;
	CBullets m_Bullet;
};