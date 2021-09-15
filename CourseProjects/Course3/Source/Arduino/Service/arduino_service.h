#ifndef ARDUINOSERVICE_H
#define ARDUINOSERVICE_H

#include <cstdint>
#include <string>
#include <type_traits>
#include <boost/asio/buffer.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/read.hpp>
#include <boost/asio/serial_port.hpp>
#include <boost/asio/write.hpp>
#include <boost/noncopyable.hpp>

class arduino_service : private boost::noncopyable
{
public:
	arduino_service(const std::string &port, uint16_t baud_rate) :
		serial_(io_, port)
	{
		serial_.set_option(boost::asio::serial_port::baud_rate(baud_rate));
	}

	template<typename _Type>
	void read(_Type &dst)
	{
		boost::asio::read(serial_, boost::asio::buffer(&dst, sizeof(_Type)));
	}

	template<typename _Type>
	void write(const _Type &src)
	{
		boost::asio::write(serial_, boost::asio::buffer(&src, sizeof(_Type)));
	}

private:
	boost::asio::io_context io_;
	boost::asio::serial_port serial_;
};

#endif // ARDUINOSERVICE_H
