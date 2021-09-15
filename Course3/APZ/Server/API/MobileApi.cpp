#include "PCH.h"
#include "Logic/Product.h"
#include "Web/Localization.h"
#include "MobileApi.h"
#include "Utility.h"

using namespace Poco::Data::Keywords;

void MobileApi::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
	response.setChunkedTransferEncoding(true);
	response.setContentType("text/json");

	std::string command = request.getURI().substr(8);
	command = command.substr(0, command.find_first_of("?"));

	Poco::Net::HTMLForm form(request, request.stream());
	if (!form.empty())
	{
		try
		{
			if (command == "authorize")
				Authorize(response, form);
			else if (command == "product-get")
				GetProducts(response, form);
			else if (command == "product-add")
				AddProduct(response, form);
			else if (command == "product-remove")
				RemoveProduct(response, form);
		}
		catch (Poco::Exception &e)
		{
			Poco::Util::Application::instance().logger().error(e.displayText());
			response.send() << "0";
		}
	}
	else if (command == "categories")
		GetCategories(response);
	else
		response.send() << "0";
}

void MobileApi::Authorize(Poco::Net::HTTPServerResponse &response, const Poco::Net::HTMLForm &form)
{
	std::string	login	= form["login"];
	std::string	pass	= form["pass"];
	std::string	token;
	int32_t		id;

	GetContext()->GetDb().NewSession() << R"(SELECT "GENERATE_TOKEN"(?, MD5(MD5(?))))", use(login), use(pass), into(token), now;
	GetContext()->GetDb().NewSession() << R"(SELECT "user_id" FROM "users" WHERE "user_login" = ? AND "user_pass" = MD5(MD5(?)) AND "user_email_valid" = TRUE)", use(login), use(pass), into(id), now;
	if (!id)
		throw Poco::Exception("Invalid login or password");
	Poco::JSON::Object::Ptr json = new Poco::JSON::Object();
	json->set("id", id);
	json->set("login", login);
	json->set("token", token);
	std::stringstream out;
	json->stringify(out);
	response.send() << out.str();
}

void MobileApi::GetProducts(Poco::Net::HTTPServerResponse &response, const Poco::Net::HTMLForm &form)
{
	Poco::AutoPtr<Poco::Util::ConfigurationView> l10n = GetContext()->GetL10n().Get("en");

	std::string	token = form["token"];
	Product		product;

	Poco::Data::Session db_session = GetContext()->GetDb().NewSession();
	Poco::Data::Statement db_statement(db_session);
	db_statement << R"(SELECT * FROM "storage_data" WHERE "user_id" = "GET_USER_BY_TOKEN"(?) AND "is_active" = TRUE)",
				 use(token),
				 into(product.id),
				 into(product.name),
				 into(product.count),
				 into(product.space),
				 into(product.date_begin),
				 into(product.date_end),
				 into(product.address),
				 range(0, 1);
	if (token.empty())
		throw Poco::Exception("Invalid login or password");

	int i = 0;
	Poco::JSON::Object::Ptr json_root = new Poco::JSON::Object;
	while (!db_statement.done())
	{
		if (!db_statement.execute())
			break;
		Poco::JSON::Object::Ptr json_obj = new Poco::JSON::Object;
		json_obj->set("id", product.id);
		json_obj->set("name", l10n->getString(product.name));
		json_obj->set("count", product.count);
		json_obj->set("space", product.space);
		json_obj->set("date", product.date_begin);
		json_obj->set("address", product.address);
		json_root->set(std::to_string(i++), json_obj);
	}

	std::stringstream out;
	json_root->stringify(out);
	response.send() << out.str();
}

void MobileApi::AddProduct(Poco::Net::HTTPServerResponse &response, const Poco::Net::HTMLForm &form)
{
	const std::string user_token = form["token"];
	const int32_t cat_id	= std::stoi(form["id"]);
	const int32_t count		= std::stoi(form["count"]);
	int32_t ware_id;
	GetContext()->GetDb().NewSession() << R"(SELECT "CALCULATE_BEST_WAREHOUSE_I"(?))", bind(cat_id), into(ware_id), now;
	GetContext()->GetDb().NewSession() << R"(CALL "STORE_PRODUCT_I"(?, ?, ?, ?))",
			   bind(ware_id), bind(cat_id), bind(user_token), bind(count), now;
}

void MobileApi::RemoveProduct(Poco::Net::HTTPServerResponse& response, const Poco::Net::HTMLForm& form)
{
	GetContext()->GetDb().NewSession() << R"(CALL "REMOVE_PRODUCT"(?))", bind(std::stoi(form["id"])), now;
}

void MobileApi::GetCategories(Poco::Net::HTTPServerResponse &response)
{
	Poco::AutoPtr<Poco::Util::ConfigurationView> l10n = GetContext()->GetL10n().Get("en");

	std::string name;
	int id;
	int i = 0;

	Poco::Data::Session db_session = GetContext()->GetDb().NewSession();
	Poco::Data::Statement db_statement(db_session);
	db_statement << R"(SELECT "category_id", "category_name" FROM "categories")", into(id), into(name), range(0, 1);

	Poco::JSON::Object::Ptr json_root = new Poco::JSON::Object;
	while (!db_statement.done())
	{
		if (!db_statement.execute())
			break;
		Poco::JSON::Object::Ptr json_obj = new Poco::JSON::Object;
		json_obj->set("id", id);
		json_obj->set("name", l10n->getString(name));
		json_root->set(std::to_string(i++), json_obj);
	}

	std::stringstream out;
	json_root->stringify(out);
	response.send() << out.str();
}
