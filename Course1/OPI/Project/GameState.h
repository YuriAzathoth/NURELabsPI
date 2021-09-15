#pragma once
#include "BaseState.h"
#include "Level.h"
class CGameState : public CBaseState
{
public:
	CGameState(RenderWindow* pRenderWindow);
	~CGameState();

	void Tick(UINT64 nElapsedTime);
	void Draw() const;
	void ProcessEvent(Event event);

private:
	CLevel*		m_pLevel;

	Vector2f	m_vecfWndSize;

	bool		m_bPause;
	bool		m_bIsCurrBtnExit;
	bool		m_bPauseBtnPressed;
	Font		m_fntPause;
	Text		m_txtPause;
	Text		m_txtBtnContinue;
	Text		m_txtBtnExit;
};

