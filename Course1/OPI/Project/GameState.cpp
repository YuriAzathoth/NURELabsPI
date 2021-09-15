#include "stdafx.h"
#include "GameState.h"
#include <ctime>


CGameState::CGameState(RenderWindow* pRenderWindow) :
	CBaseState(pRenderWindow),
	m_bPause(false),
	m_bPauseBtnPressed(false),
	m_bIsCurrBtnExit(false)
{
	m_pLevel	= new CLevel(pRenderWindow->getSize());

	m_vecfWndSize = (Vector2f)m_pRenderWindow->getSize();

	m_fntPause.loadFromFile("MATURASC.TTF");

	m_txtPause.setFont(m_fntPause);
	m_txtPause.setString("Paused!");
	m_txtPause.setCharacterSize(40);
	m_txtPause.setPosition(m_vecfWndSize.x / 2, m_vecfWndSize.y / 2);
	m_txtPause.setFillColor(Color(10, 50, 150));

	m_txtBtnContinue.setFont(m_fntPause);
	m_txtBtnContinue.setString("Continue");
	m_txtBtnContinue.setCharacterSize(20);
	m_txtBtnContinue.setPosition(m_vecfWndSize.x / 2, m_vecfWndSize.y / 2 + 44);
	m_txtBtnContinue.setFillColor(Color(150, 50, 10));

	m_txtBtnExit.setFont(m_fntPause);
	m_txtBtnExit.setString("Exit");
	m_txtBtnExit.setCharacterSize(20);
	m_txtBtnExit.setPosition(m_vecfWndSize.x / 2 + 100, m_vecfWndSize.y / 2 + 44);
	m_txtBtnExit.setFillColor(Color(10, 50, 150));
}


CGameState::~CGameState()
{
	delete m_pLevel;
	m_pRenderWindow->setView(m_pRenderWindow->getDefaultView());
}


void CGameState::Tick(UINT64 nElapsedTime)
{
	m_bErrorState = m_bErrorState || m_pLevel->IsErrorOccured();

	if (!m_bPause)
		m_pLevel->Tick(nElapsedTime);
	else // if (bPause)
		ChangeState(STATE_MENU, true);

	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		if (m_bPauseBtnPressed == false)
		{
			m_bPauseBtnPressed = true;
			m_bPause = !m_bPause;
		}
	}
	else
		m_bPauseBtnPressed = false;

	if (m_pLevel->GetPlayer()->IsAlive() == false)
		ChangeState(STATE_MENU, true);
}


void CGameState::Draw() const
{
	m_pLevel->Draw(m_pRenderWindow);

	if (m_bPause)
	{
		m_pRenderWindow->draw(m_txtPause);
		m_pRenderWindow->draw(m_txtBtnContinue);
		m_pRenderWindow->draw(m_txtBtnExit);
	}
}


void CGameState::ProcessEvent(Event event)
{

}