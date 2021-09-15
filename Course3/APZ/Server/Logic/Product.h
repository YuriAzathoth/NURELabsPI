#ifndef PRODUCT_H
#define PRODUCT_H

struct Product
{
	std::string	name;
	std::string	address;
	std::string	login;
	std::string	date_begin;
	std::string	date_end;
	uint32_t	id;
	uint16_t	space;
	uint16_t	count;
};

#endif // PRODUCT_H
