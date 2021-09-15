#include "PCH.h"
#include "Shared/LocalizationSystem.h"

LocalizationSystem::LocalizationSystem() : m_dictionary(new Poco::Util::LayeredConfiguration)
{
	const std::string langs = Poco::Util::Application::instance().config().getString("Localization.lang", "en");
	const Poco::StringTokenizer l10ns(langs, ",");
	for (const std::string &lang : l10ns)
	{
		std::stringstream l10n_path;
		l10n_path << Poco::Util::Application::instance().config().getString("Localization.dir", "../share/Localization");
		l10n_path << "/" << lang << ".loc";
		m_dictionary->add(new Poco::Util::PropertyFileConfiguration(l10n_path.str()));
	}
}
