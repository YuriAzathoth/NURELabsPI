#ifndef LOCALIZATIONSYSTEM_H
#define LOCALIZATIONSYSTEM_H

class LocalizationSystem
{
public:
	LocalizationSystem();
	Poco::AutoPtr<Poco::Util::ConfigurationView> Get(const std::string &lang)
	{
		return new Poco::Util::ConfigurationView(lang, m_dictionary);
	}

private:
	Poco::AutoPtr<Poco::Util::LayeredConfiguration> m_dictionary;
};

#endif // LOCALIZATIONSYSTEM_H
