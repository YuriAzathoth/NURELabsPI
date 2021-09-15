#include "PCH.h"
#include "Web/Localization.h"
#include "EmailSystem.h"
#include "IObject.h"
#include "Utility.h"

EmailSystem::EmailSystem()
{
	Poco::Util::LayeredConfiguration &config = Poco::Util::Application::instance().config();
	m_provider	= config.getString("Email.provider");
	m_sender	= config.getString("Email.address");
	m_password	= config.getString("Email.password");
	m_port		= config.getInt("Email.port");
}

void EmailSystem::SendVerification(const std::string &receiver, std::string name, const std::string &token, const Localization &l10n) const
{
	std::stringstream body;
	body << l10n.Get("email.header") << " " << name << "\r\n\r\n";
	body << l10n.Get("email.body") << "https://localhost:9980/user-confirm?token=" << token << "\r\n\r\n";
	Send(receiver, l10n.Get("email.subject"), body.str());
}

void EmailSystem::Send(const std::string &receiver, const std::string &subject, const std::string &body) const
{
	try
	{
		Poco::Net::MailMessage message;
		message.setSender(m_sender);
		message.addRecipient(Poco::Net::MailRecipient(Poco::Net::MailRecipient::PRIMARY_RECIPIENT, receiver));
		message.setSubject(subject);
		message.addContent(new Poco::Net::StringPartSource(body));

		Poco::Net::SecureSMTPClientSession session(m_provider, m_port);
		session.login();
		if (!session.startTLS())
			throw Poco::Exception("Failed to start TLS connection.");
		session.login(Poco::Net::SecureSMTPClientSession::AUTH_LOGIN, m_sender, m_password);
		session.sendMessage(message);
		session.close();
	}
	catch (Poco::Exception &e)
	{
		Poco::Util::Application::instance().logger().error(e.displayText());
	}
}
