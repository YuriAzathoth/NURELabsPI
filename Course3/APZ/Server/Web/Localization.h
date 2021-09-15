#ifndef LOCALIZATION_H
#define LOCALIZATION_H

#include "Shared/ServerContext.h"
#include "Shared/IObject.h"
#include "Web/CookiesManager.h"
class CookiesManager;

class Localization : public IObject
{
public:
	Localization(ServerContext* context, CookiesManager &cookies)  :
		IObject(context),
		m_dictionary(GetContext()->GetL10n().Get(cookies.GetL10n()))
	{}
	const std::string Get(const std::string &key) const
	{
		return m_dictionary->getString(key, key);
	}

private:
	Poco::AutoPtr<Poco::Util::ConfigurationView> m_dictionary;
};

#endif // LOCALIZATION_H
