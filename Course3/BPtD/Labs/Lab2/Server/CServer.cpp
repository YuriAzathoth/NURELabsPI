#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include "CServer.h"

using namespace std;

CServer::CServer(boost::asio::io_context &io_context, int port, TFNCallback receiver) :
	socket_(io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port)),
	receiver_(receiver)
{
	StartReceive();
}

void CServer::StartReceive()
{
	socket_.async_receive_from(boost::asio::buffer(recv_buffer_),
							   remote_endpoint_,
							   boost::bind(&CServer::OnReceive, this,
											boost::asio::placeholders::error,
											boost::asio::placeholders::bytes_transferred));
}

void CServer::SendResponse(const char* data)
{
	socket_.async_send_to(boost::asio::buffer(data, strlen(data)),
						  remote_endpoint_,
						  boost::bind(&CServer::OnSend, this, data,
									  boost::asio::placeholders::error));
	StartReceive();
}

void CServer::OnReceive(const boost::system::error_code &error, size_t received_size)
{
	if (error)
	{
		cout << "Server receive error: " << error.message() << endl;
		return;
	}

	char* string_received = recv_buffer_.data();
	string_received[received_size] = '\0';
	receiver_(string_received);
	StartReceive();
}

void CServer::OnSend(const char*, const boost::system::error_code &error)
{
	if (error)
	{
		cout << "Server response error: " << error.message() << endl;
		return;
	}
}
