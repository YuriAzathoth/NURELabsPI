#pragma once
#include <bitset>
class CBaseState
{
public:
	CBaseState(RenderWindow* pRenderWindow) : m_nNextState(0), m_bDelThisState(false), m_bErrorState(false)
	{
		m_pRenderWindow = pRenderWindow;
	}
	virtual ~CBaseState() {};

	virtual void Tick(UINT64 nElapsedTime) = 0;
	virtual void Draw() const = 0;
	virtual void ProcessEvent(Event event) {};

	UINT8 GetNextState() const { return m_nNextState; }
	void ResetNextState() { m_nNextState = 0; }
	bool GetDelThisState() const { return m_bDelThisState; }
	bool IsErrorOccured() const { return m_bErrorState; }

	enum e_StatesId
	{
		STATE_MENU = 1,
		STATE_GAME
	};

protected:
	RenderWindow*	m_pRenderWindow;

	bitset<32>		m_bKeyMap;

	void ChangeState(UINT8 nStateId, bool bDeleteCurrent)
	{
		m_nNextState = nStateId;
		m_bDelThisState = bDeleteCurrent;
	}
	UINT8			m_nNextState;
	bool			m_bDelThisState;

	bool			m_bErrorState;
};