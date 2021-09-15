#ifndef SERVERCONTEXT_H
#define SERVERCONTEXT_H

#include "DatabaseSystem.h"
#include "EmailSystem.h"
#include "LocalizationSystem.h"

class ServerContext
{
public:
	DatabaseSystem		&GetDb()	noexcept { return m_database; }
	LocalizationSystem	&GetL10n()	noexcept { return m_l10n; }
	EmailSystem			&GetEmail()	noexcept { return m_email; }

private:
	DatabaseSystem		m_database;
	LocalizationSystem	m_l10n;
	EmailSystem			m_email;
};

#endif // SERVERCONTEXT_H
