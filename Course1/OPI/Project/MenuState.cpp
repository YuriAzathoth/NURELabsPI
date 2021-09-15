#include "stdafx.h"
#include "MenuState.h"


CMenuState::CMenuState(RenderWindow* pRenderWindow) : CBaseState(pRenderWindow), m_nCurrMenuItem(0)
{
	m_fntMenuFont.loadFromFile("maturasc.ttf");

	m_rshpBackground.setFillColor(Color(255, 255, 255));
	m_rshpBackground.setPosition(Vector2f(0, 0));
	m_rshpBackground.setSize(Vector2f((float)m_pRenderWindow->getSize().x, (float)m_pRenderWindow->getSize().y));

	CreateMenuItem("New Game", 4, true);
	CreateMenuItem("Continue", 3);
	CreateMenuItem("Scores", 2);
	CreateMenuItem("Exit", 1);
}


void CMenuState::Tick(UINT64 nELapsedTime)
{
	if (!m_bKeyMap[0] && m_nCurrMenuItem > 0)
	{
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			m_bKeyMap[0] = true;
			m_nCurrMenuItem--;
			m_texMenuItems[m_nCurrMenuItem].setFillColor(Color(255, 0, 0));
			m_texMenuItems[m_nCurrMenuItem + 1].setFillColor(Color(0, 0, 255));
		}
	}
	if (!Keyboard::isKeyPressed(Keyboard::Up))
		m_bKeyMap[0] = false;

	if (!m_bKeyMap[1] && m_nCurrMenuItem < 3)
	{
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			m_bKeyMap[1] = true;
			m_nCurrMenuItem++;
			m_texMenuItems[m_nCurrMenuItem].setFillColor(Color(255, 0, 0));
			m_texMenuItems[m_nCurrMenuItem - 1].setFillColor(Color(0, 0, 255));
		}
	}
	if (!Keyboard::isKeyPressed(Keyboard::Down))
		m_bKeyMap[1] = false;

	if (Keyboard::isKeyPressed(Keyboard::Return))
	{
		switch (m_nCurrMenuItem)
		{
		case 0:	// New Game
			ChangeState(STATE_GAME, true);
			break;
		case 1: // Continue
			break;
		case 2: // Scores
			break;
		case 3: // Exit
			m_pRenderWindow->close();
			break;
		}
	}
}


void CMenuState::Draw() const
{
	m_pRenderWindow->draw(m_rshpBackground);

	for (int i = 0; i < 4; i++)
		m_pRenderWindow->draw(m_texMenuItems[i]);
}


void CMenuState::CreateMenuItem(const String &sText, UINT8 nId, bool bActive)
{
	const UINT8 nPos = 4 - nId;
	m_texMenuItems[nPos].setFont(m_fntMenuFont);
	m_texMenuItems[nPos].setCharacterSize(48);
	m_texMenuItems[nPos].setString(sText);
	m_texMenuItems[nPos].setPosition(Vector2f((float)32, (float)m_pRenderWindow->getSize().y - 64 * (float)nId));
	if (bActive)
		m_texMenuItems[nPos].setFillColor(Color(255, 0, 0));
	else
		m_texMenuItems[nPos].setFillColor(Color(0, 0, 255));
}