#include "stdafx.h"
#include "Core.h"
#include "MenuState.h"
#include "GameState.h"


#ifdef _DEBUG
#pragma comment(lib, "sfml-graphics-d.lib")
#pragma comment(lib, "sfml-window-d.lib")
#pragma comment(lib, "sfml-system-d.lib")
#else
#pragma comment(lib, "sfml-graphics.lib")
#pragma comment(lib, "sfml-window.lib")
#pragma comment(lib, "sfml-system.lib")
#endif

#pragma comment(lib, "tinyxml2.lib")


CCore::CCore() : m_bIsFullscreen(false)
{
	srand((unsigned int)time(NULL));

	m_pRenderWindow = new RenderWindow(VideoMode(1024, 768), "The Game");
	m_pRenderWindow->setMouseCursorVisible(false);

	m_pClock = new Clock();

	m_States.push_back(new CMenuState(m_pRenderWindow));
}


CCore::~CCore()
{
	if (m_pRenderWindow)
		delete m_pRenderWindow;
	if (m_pClock)
		delete m_pClock;

	while (!m_States.empty())
	{
		if (m_States.back())
			delete m_States.back();
		m_States.pop_back();
	}
}


void CCore::Do()
{
	m_pClock->restart();

	bool bErrorState = false;
	while (m_pRenderWindow->isOpen())
	{
		Event event;
		while (m_pRenderWindow->pollEvent(event))
		{
			if (event.type == Event::Closed || bErrorState)
				m_pRenderWindow->close();
			m_States.back()->ProcessEvent(event);
		}

		if (Keyboard::isKeyPressed(Keyboard::F11))
		{
			m_pRenderWindow->close();
			delete m_pRenderWindow;
			if (!m_bIsFullscreen)
				m_pRenderWindow = new RenderWindow(VideoMode(1024, 768), "The Game", Style::Fullscreen);
			else
				m_pRenderWindow = new RenderWindow(VideoMode(1024, 768), "The Game");
		}

		m_pRenderWindow->clear();

		ProcessStates();
		if (!m_States.empty())
		{
			CBaseState* pCurrState = m_States.back();
			bErrorState = pCurrState->IsErrorOccured();

			pCurrState->Tick(m_pClock->getElapsedTime().asMicroseconds());
			pCurrState->Draw();
		}
		m_pRenderWindow->display();

		m_pClock->restart();
	}
}


void CCore::ProcessStates()
{
	UINT8 nNextState = m_States.back()->GetNextState();

	if (m_States.back()->GetDelThisState())
	{
		delete m_States.back();
		m_States.pop_back();
	}

	if (nNextState)
	{
		switch (nNextState)
		{
		case CBaseState::STATE_MENU:
			m_States.push_back(new CMenuState(m_pRenderWindow));
			break;
		case CBaseState::STATE_GAME:
			m_States.push_back(new CGameState(m_pRenderWindow));
			break;
		}
		m_States.back()->ResetNextState();
	}
}


int APIENTRY WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	CCore core;
	core.Do();
	return 0;
}