#ifndef COOKIESHOLDER_H
#define COOKIESHOLDER_H

class CookiesManager
{
public:
	CookiesManager(const Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response);

	std::string	GetToken	() const	{ return Get(TOKEN); }
	std::string	GetL10n		()			{ return Get(L10N, "en"); }
	int			GetPage		() 			{ return std::stoi(Get(PAGE, "0")); }
	std::string	GetError	()			{ const std::string error = Get(ERRSTR); ResetError(); return error; }
	bool		IsError		() const	{ return !Get(ERRSTR).empty(); }

	void SetToken	(const std::string &token)	{ Set(TOKEN, token); }
	void SetL10n	(const std::string &lang)	{ Set(L10N, lang); }
	void SetPage	(int page)					{ Set(PAGE, std::to_string(page)); }
	void SetError	(const std::string &error)	{ Set(ERRSTR, error); }

	void ResetToken()	{ SetToken(""); }
	void ResetError()	{ SetError(""); }

private:
	std::string	Get(const std::string &name) const;
	std::string	Get(const std::string &name, const std::string &defval);
	void		Set(const std::string &name, const std::string &value);

	Poco::Net::NameValueCollection		m_cookies;
	const Poco::Net::HTTPServerRequest	&m_request;
	Poco::Net::HTTPServerResponse		&m_response;

	static constexpr char TOKEN	[]	= "token";
	static constexpr char L10N	[]	= "l10n";
	static constexpr char PAGE	[]	= "page";
	static constexpr char ERRSTR[]	= "error";
};

#endif // COOKIESHOLDER_H
