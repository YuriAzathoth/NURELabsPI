#ifndef EMAILSYSTEM_H
#define EMAILSYSTEM_H

class Localization;

class EmailSystem
{
public:
	EmailSystem();
	void SendVerification(const std::string &receiver, std::string name, const std::string &token, const Localization &l10n) const;

private:
	void Send(const std::string &receiver, const std::string &subject, const std::string &body) const;

	std::string	m_provider;
	std::string	m_sender;
	std::string	m_password;
	int			m_port;
};

#endif // EMAILSYSTEM_H
