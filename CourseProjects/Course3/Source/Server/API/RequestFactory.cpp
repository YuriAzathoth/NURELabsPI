#include <Poco/Net/HTTPServerRequest.h>
#include "Agriculture/CreateAgriculture.h"
#include "Agriculture/DeleteAgriculture.h"
#include "Agriculture/GetAgriculturesTable.h"
#include "Agriculture/ReadAgriculture.h"
#include "Agriculture/UpdateAgriculture.h"
#include "Field/CreateField.h"
#include "Field/DoMeasurement.h"
#include "Field/DeleteField.h"
#include "Field/GetFieldsTable.h"
#include "Field/ReadField.h"
#include "Field/UpdateField.h"
#include "TaskTable/GenerateTaskTable.h"
#include "TaskTable/GetTaskTable.h"
#include "User/EditProfile.h"
#include "User/LogIn.h"
#include "User/SignUp.h"
#include "InvalidRequest.h"
#include "RequestFactory.h"
#include "RequestParser.h"

Poco::Net::HTTPRequestHandler*
RequestFactory::createRequestHandler(const Poco::Net::HTTPServerRequest &request)
{
	const RequestParser uri(request.getURI());
	if (!uri.IsValid())
		return new InvalidRequest;

	if (uri.GetType() == "user")
	{
		if (uri.GetAction() == "login")
			return new LogIn;
		else if (uri.GetAction() == "signup")
			return new SignUp;
		else if (uri.GetAction() == "edit")
			return new EditProfile;
	}
	else if (uri.GetType() == "agriculture")
	{
		if (uri.GetAction() == "create")
			return new CreateAgriculture;
		else if (uri.GetAction() == "read")
			return new ReadAgriculture;
		else if (uri.GetAction() == "update")
			return new UpdateAgriculture;
		else if (uri.GetAction() == "delete")
			return new DeleteAgriculture;
		else if (uri.GetAction() == "table")
			return new GetAgriculturesTable;
	}
	else if (uri.GetType() == "field")
	{
		if (uri.GetAction() == "create")
			return new CreateField;
		else if (uri.GetAction() == "read")
			return new ReadField;
		else if (uri.GetAction() == "delete")
			return new DeleteField;
		else if (uri.GetAction() == "update")
			return new UpdateField;
		else if (uri.GetAction() == "table")
			return new GetFieldsTable;
		else if (uri.GetAction() == "irrigate")
			return new DoMeasurement;
	}
	else if (uri.GetType() == "task")
	{
		if (uri.GetAction() == "get")
			return new GetTaskTable;
		else if (uri.GetAction() == "create")
			return new GenerateTaskTable;
	}

	return new InvalidRequest;
}
