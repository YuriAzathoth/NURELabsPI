#include "PCH.h"
#include "PageManager.h"
#include "User.h"

PageManager::EPage PageManager::GetHome(bool is_logged, int role) noexcept
{
	if (!is_logged)
		return EPage::USER_LOGIN;
	if (static_cast<User::ERole>(role) == User::ERole::ADMINISTRATOR)
		return EPage::HOME_ADMIN_WAREHOUSES;
	else
		return EPage::HOME_CLIENT;
}
