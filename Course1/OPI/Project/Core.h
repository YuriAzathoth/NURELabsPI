#pragma once
#include "BaseState.h"
#include <vector>
class CCore
{
public:
	CCore();
	~CCore();
	void Do();

private:
	RenderWindow*	m_pRenderWindow;
	Clock*			m_pClock;

	typedef vector<CBaseState*>		TStatesArr;
	typedef TStatesArr::iterator	TStaterIt;
	TStatesArr		m_States;

	void			ProcessStates();

	bool			m_bIsFullscreen;
};