#include "stdafx.h"
#include "Enemy.h"
#include <cmath>
#include "GeomFunc.h"
#include "Level.h"


CEnemy::CEnemy(Vector2f vecfPos, CLevel* pParentLevel) : m_bIsDead(false), m_Bullet("Enemy_Bullet", m_pParentLevel), m_fHealth(1.0f)
{
	m_pParentLevel = pParentLevel;

	LoadSprite(0, "enemy_bottom.png");
	GetSprite(0).setPosition(vecfPos);

	LoadSprite(1, "enemy_top.png");
	GetSprite(1).setPosition(GetSprite(0).getPosition());

	SetCenterOrigin(0);
	SetCenterOrigin(1);

	m_Bullet.SetDamage(0.04f);
	m_Bullet.SetFireRate(8.0f);
	m_Bullet.SetRange(1000.0f);
	m_Bullet.SetScale(0.5f);
	m_Bullet.SetSpeed(1.0f);
}


CEnemy::~CEnemy()
{
}


void CEnemy::Tick(UINT64 nElapsedTime)
{
	Vector2f vecuPlayerPos = m_pParentLevel->GetPlayer()->GetPosition();
	Vector2f vecuEnemyPos = GetSprite(0).getPosition();

	float fDx = vecuPlayerPos.x - vecuEnemyPos.x;
	float fDy = vecuPlayerPos.y - vecuEnemyPos.y;
	float fDl = sqrt(fDx * fDx + fDy * fDy);
	float fAngle = RadToDeg(atan2f(fDx, fDy)) + 90.0f;

	if (fDl > 250.0f)
		GetSprite(0).move((float)nElapsedTime / -500.0f * cosf(DegToRad(fAngle)), (float)nElapsedTime / 500.0f * sinf(DegToRad(fAngle)));

	GetSprite(0).setRotation(-fAngle - 90.0f);
	GetSprite(1).setPosition(GetSprite(0).getPosition());
	GetSprite(1).setRotation(GetSprite(0).getRotation());

	if (fDl <= 600.0f)
		Fire();

	m_Bullet.Tick(nElapsedTime);
}


void CEnemy::Fire()
{
	m_Bullet.Fire(GetSprite(1).getRotation() - 90.0f, GetSprite(1).getPosition());
}