#pragma once
#include "BaseState.h"
class CMenuState : public CBaseState
{
public:
	CMenuState(RenderWindow* pRenderWindow);

	void Tick(UINT64 nElapsedTime);
	void Draw() const;

private:
	void	CreateMenuItem(const String &sText, UINT8 nId, bool bActive = false);
	UINT8	m_nCurrMenuItem;
	Font	m_fntMenuFont;
	Text	m_texMenuItems[4];

	RectangleShape m_rshpBackground;
};
