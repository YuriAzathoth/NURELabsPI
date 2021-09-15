#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <Poco/JSON/Object.h>
#include <Poco/JSON/Parser.h>
#include <Poco/JSON/Stringifier.h>
#include "arduino_service.h"
#include "common.h"

constexpr char IOT_PORT[]		= "COM3";
constexpr uint16_t BAUD_RATE	= 9600;

template<typename _Data>
union net_object
{
	_Data data;
	uint8_t buffer[sizeof(data)];

	bool verify_checksum() const noexcept
	{
		return data.checksum == data.get_checksum();
	}
	void set_checksum() noexcept
	{
		data.checksum = data.get_checksum();
	}
};

struct init_s
{
	char email[32];
	char password[32];
	uint32_t id;
	uint8_t checksum;

	uint8_t get_checksum() const noexcept
	{
		uint8_t sum = 0;
		for (uint8_t i = 0; i < 16; ++i)
			sum ^= (uint8_t)id;
		for (uint8_t i = 0; i < 32; ++i)
			sum ^= email[i] ^ password[i];
		return sum;
	}
};

struct config_s
{
	uint8_t hmin;
	uint8_t hmax;
	uint8_t checksum;

	uint8_t get_checksum() const noexcept
	{
		return hmin ^ hmax;
	}
};

struct response_s
{
	uint32_t id;
	uint8_t humidity;
	uint8_t checksum;

	uint8_t get_checksum() const noexcept
	{
		return humidity ^ (uint8_t)id;
	}
};

int main()
{
	net_object<init_s> init;
	net_object<config_s> config;
	net_object<response_s> measurement;
	std::stringstream request;

	setlocale(LC_ALL, "");

	try
	{
		arduino_service arduino(IOT_PORT, BAUD_RATE);
		arduino.read(init.buffer);

		request.str("");
		Poco::JSON::Object::Ptr requestJson = new Poco::JSON::Object;
		requestJson->set("email",	std::string(init.data.email));
		requestJson->set("password",std::string(init.data.password));
		requestJson->stringify(request);
		std::string response = ServerRequest("/user/login", request.str());

		std::cout << "DEVICE" << std::endl;
		std::cout << "Email:    " << init.data.email << std::endl;
		std::cout << "Password: " << init.data.password << std::endl;
		std::cout << "Field:    " << init.data.id << std::endl;
		std::cout << "Raw:" << std::endl;
		for (const char c : init.buffer)
			printf("%x ", c);
		std::cout << std::endl << std::endl;

		Poco::JSON::Parser parser;
		parser.parse(response);
		Poco::JSON::Object::Ptr responseJson = parser.result().extract<Poco::JSON::Object::Ptr>();
		const std::string token = responseJson->getValue<std::string>("token");

		request.str("");
		requestJson = new Poco::JSON::Object;
		requestJson->set("token",	token);
		requestJson->set("id",		init.data.id);
		requestJson->stringify(request);
		response = ServerRequest("/field/read", request.str());

		parser.parse(response);
		responseJson = parser.result().extract<Poco::JSON::Object::Ptr>();
		Poco::JSON::Object::Ptr agricultureJson = responseJson->getObject("agriculture");

		config.data.hmin = agricultureJson->getValue<uint8_t>("humidity_min");
		config.data.hmax = agricultureJson->getValue<uint8_t>("humidity_max");
		config.set_checksum();
		arduino.write(config.buffer);

		std::cout << "CONFIG" << std::endl;
		std::cout << "HMin: " << (int)config.data.hmin << std::endl;
		std::cout << "HMax: " << (int)config.data.hmax << std::endl;
		std::cout << "Raw:" << std::endl;
		for (const char c : config.buffer)
			printf("%x ", c);
		std::cout << std::endl << std::endl;

		do
			arduino.read(measurement.buffer);
		while (init.data.id != measurement.data.id || !measurement.verify_checksum());

		std::cout << "MEASURE" << std::endl;
		std::cout << "Id:        " << (int)measurement.data.id << std::endl;
		std::cout << "Humidity:  " << (int)measurement.data.humidity << std::endl;
		std::cout << "Raw:" << std::endl;
		for (const char c : measurement.buffer)
			printf("%x ", c);
		std::cout << std::endl << std::endl;

		if (measurement.verify_checksum())
		{
			request.str("");
			requestJson = new Poco::JSON::Object;
			requestJson->set("id",			init.data.id);
			requestJson->set("humidity",	measurement.data.humidity);
			requestJson->set("token",		token);
			requestJson->stringify(request);
			ServerRequest("/field/irrigate", request.str());
		}
		else
			std::cout << "Invalid checksum" << std::endl;

		arduino.write('\t');
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
