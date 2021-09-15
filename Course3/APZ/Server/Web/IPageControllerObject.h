#ifndef IPAGECONTROLLEROBJECT_H
#define IPAGECONTROLLEROBJECT_H

#include "Web/PageManager.h"

class IPageControllerObject
{
public:
	IPageControllerObject(PageManager &pagemgr) : m_pagemgr(pagemgr) {}
protected:
    void SetPage(PageManager::EPage page) noexcept { m_pagemgr.Set(page); }
private:
	PageManager &m_pagemgr;
};

#endif // IPAGECONTROLLEROBJECT_H
