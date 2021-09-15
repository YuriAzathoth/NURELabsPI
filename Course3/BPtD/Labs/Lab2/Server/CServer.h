#ifndef CSERVER_H
#define CSERVER_H

#include <winsock2.h>
#include <windows.h>

#include <boost/array.hpp>
#include <boost/function.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/udp.hpp>
#include <boost/system/error_code.hpp>

class CServer
{
public:
	using TFNCallback = boost::function<void(const char*)>;

	CServer(boost::asio::io_context &io_context, int port, TFNCallback receiver);

    void SendResponse(const char* data);

private:
	void StartReceive();
	void OnReceive(const boost::system::error_code &error, size_t received_size);
	void OnSend(const char* data, const boost::system::error_code &error);

	boost::asio::ip::udp::socket socket_;
	boost::asio::ip::udp::endpoint remote_endpoint_;
	boost::array<char, 2048> recv_buffer_;
	TFNCallback receiver_;

	CServer(const CServer&) = delete;
	CServer(CServer&&) = delete;
	CServer operator=(const CServer&) = delete;
	CServer operator=(CServer&&) = delete;
};

#endif // CSERVER_H
