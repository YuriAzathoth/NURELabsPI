#include "stdafx.h"
#include "Bullets.h"
#include "Level.h"
#include <cmath>
#include "GeomFunc.h"
#include "Player.h"


CBullets::CBullets(string sObjName, CLevel* pParent) :
	CObjectList(sObjName),
	m_fSpeed(1.0f),
	m_fRange(800.0f),
	m_fDamage(1.0f),
	m_fScale(1.0f),
	m_fFireRate(1.0f)
{
	SetFireRate(1.0f);
	m_nShotsTimer = m_nDelay;
	m_pParentLevel = pParent;
}


void CBullets::Tick(UINT64 nElapsedTime)
{
	if (m_nShotsTimer <= m_nDelay)
		m_nShotsTimer += nElapsedTime;

	if (!m_Sprites.empty())
	{
		for (TSpritesIt it = m_Sprites.begin(); it != m_Sprites.end();)
		{
			if ((((CProjectile*)(*it))->GetPathDone() < m_fRange) && !CheckCollision((*it)->GetSprite()))
			{
				float fAngle = (*it)->GetSprite().getRotation() - 90.0f;
				float fDl = m_fSpeed * (float)((double)nElapsedTime / 200.0);

				float fDx = fDl * cosf(DegToRad(fAngle));
				float fDy = fDl * sinf(DegToRad(fAngle));
				(*it)->GetSprite().move(fDx, fDy);

				((CProjectile*)(*it))->IncPathDone(fDl);
				it++;
			}
			else
			{
				delete (*it);
				it = m_Sprites.erase(it);
			}
		}
	}
}


void CBullets::Fire(float fAngle, Vector2f vPosf, float fStartDist)
{
	if (m_nShotsTimer > m_nDelay)
	{
		Sprite &rNewSpr = LoadSprite("Bullet.png");

		rNewSpr.setPosition(vPosf);
		SetCenterOrigin();
		rNewSpr.setRotation(fAngle + 90.0f);

		float fDx = fStartDist * cosf(DegToRad(fAngle));
		float fDy = fStartDist * sinf(DegToRad(fAngle));
		rNewSpr.move(fDx, fDy);

		if (m_fScale != 1)
			rNewSpr.setScale(Vector2f(m_fScale, m_fScale));

		m_nShotsTimer -= m_nDelay;
	}
}


bool CBullets::CheckCollision(const Sprite& sprSprite)
{
	for (TSpritesIt itSpr = m_Sprites.begin(); itSpr != m_Sprites.end(); itSpr++)
	{
		if (m_sObjName == "Bullet_Player")
		{
			for (list<CEnemy*>::iterator it = m_pParentLevel->GetEnemyList().begin(); it != m_pParentLevel->GetEnemyList().end(); it++)
			{
				if (((*itSpr)->GetSprite().getPosition().x > (*it)->GetPosition().x - (*it)->GetSize().x / 2) &&
					((*itSpr)->GetSprite().getPosition().x < (*it)->GetPosition().x + (*it)->GetSize().x / 2) &&
					((*itSpr)->GetSprite().getPosition().y >(*it)->GetPosition().y - (*it)->GetSize().y / 2) &&
					((*itSpr)->GetSprite().getPosition().y < (*it)->GetPosition().y + (*it)->GetSize().y / 2))
				{
					(*it)->Hit(m_fDamage);
					m_pParentLevel->AddScore(1);
					return true;
				}
			}
		}
		else
		{
			CPlayer* pPlayer = CPlayer::sm_pPlayer;
			if (((*itSpr)->GetSprite().getPosition().x > pPlayer->GetPosition().x - pPlayer->GetSize().x / 2) &&
				((*itSpr)->GetSprite().getPosition().x < pPlayer->GetPosition().x + pPlayer->GetSize().x / 2) &&
				((*itSpr)->GetSprite().getPosition().y > pPlayer->GetPosition().y - pPlayer->GetSize().y / 2) &&
				((*itSpr)->GetSprite().getPosition().y < pPlayer->GetPosition().y + pPlayer->GetSize().y / 2))
			{
				pPlayer->Hit(m_fDamage);
				return true;
			}
		}
	}
	return false;
}