#ifndef WAREHOUSE_H
#define WAREHOUSE_H

struct Warehouse
{
	std::string	address;
	std::string	ip;
	float		tempo;
	uint32_t	id;
	uint16_t	cost;
	uint16_t	space_free;
	uint16_t	space_busy;
	uint8_t		humidity;
};

#endif // WAREHOUSE_H
