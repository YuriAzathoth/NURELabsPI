#include <clocale>
#include <cstring>
#include <exception>
#include <iostream>
#include <sstream>
#include <pugixml.hpp>
#include <wx/app.h>
#include "CMainDialog.h"

using namespace std;
using namespace pugi;

CMainDialog::CMainDialog() :
	IMainDialog(nullptr),
	server_(io_context_, 2345, std::bind(&CMainDialog::OnServerReceived, this, placeholders::_1)),
	server_thread_([this](){ io_context_.run(); })
{
}

void CMainDialog::OnInit(wxInitDialogEvent&)
{
	server_thread_.detach();
}

void CMainDialog::OnClose(wxCloseEvent&)
{
	wxExit();
}

void CMainDialog::OnServerReceived(const char* received_data)
{
	if (!strncmp(received_data, "init", 4))
		SendPublicKey();
	else
		DecryptForm(received_data);
}

void CMainDialog::SendPublicKey()
{
	char key[512];
	cryptor_.GetPublicKey(key);
	xml_document xml;
	xml.append_child("init").append_child("key").append_attribute("value").set_value(key);
	stringstream response;
	xml.save(response);
	server_.SendResponse(response.str().c_str());
}

void CMainDialog::DecryptForm(const char* received_data)
{
	xml_document xml;
	xml.load_string(received_data);
	xml_node root = xml.child("form");
	const char* login = root.child("login").attribute("value").as_string();
	const char* pass = root.child("pass").attribute("value").as_string();

	char result[512];
	cryptor_.Decrypt(result, login);
	wxString log = "Received data: login=";
	log += result;

	cryptor_.Decrypt(result, pass);
	log += " pass=";
	log += result;

	m_txtLog->SetValue(m_txtLog->GetValue() + log + "\n");
}
