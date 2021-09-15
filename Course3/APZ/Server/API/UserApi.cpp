#include "PCH.h"
#include "Web/WebContext.h"
#include "UserApi.h"

void UserApi::HandleControl()
{
	User &user = m_context->GetUser();
	if (IsCommand("login"))
		user.LogIn(GetFormData("login"), GetFormData("pass"));
	else if (IsCommand("logout"))
		user.LogOut();
	else if (IsCommand("register"))
		user.Register
		(
			GetFormData("login"),
			GetFormData("pass1"),
			GetFormData("pass2"),
			GetFormData("email"),
			GetFormData("name")
		);
	else if (IsCommand("confirm"))
		user.Confirm(GetFormData("token"));
	else if (IsCommand("edit-login"))
		user.EditLogin(GetFormData("login"));
	else if (IsCommand("edit-pass"))
		user.EditPass(GetFormData("pass1"), GetFormData("pass2"));
	else if (IsCommand("edit-email"))
		user.EditEmail(GetFormData("email"));
	else if (IsCommand("edit-name"))
		user.EditName(GetFormData("name"));
	else
		Poco::Util::Application::instance().logger().error("Invalid AccountController command");
}
