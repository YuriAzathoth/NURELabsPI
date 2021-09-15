#ifndef WEBPAGESTATEAPI_H
#define WEBPAGESTATEAPI_H

#include "BaseApi.h"

class WebPageStateApi : public BaseApi
{
public:
	WebPageStateApi(ServerContext* context, const std::string &command) : BaseApi(context, command), m_command(command) {}

private:
	void HandleControl() override final;
	void GenerateGranted();
	void SetPage();

	std::unordered_map<std::string, PageManager::EPage> m_pages;
    const std::string m_command;
};

#endif // WEBPAGESTATEAPI_H
