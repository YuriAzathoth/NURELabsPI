#ifndef WAREHOUSETABLE_H
#define WAREHOUSETABLE_H

#include "Shared/IObject.h"
#include "Web/ICookieDependentObject.h"
#include "Warehouse.h"

class WarehouseTable : public IObject, public ICookieDependentObject
{
public:
	WarehouseTable(ServerContext* global_context, CookiesManager &cookies);
	const std::vector<Warehouse> &Get() const noexcept { return m_warehouses; }

	bool Register	(std::string address, uint16_t space, uint16_t cost, const std::string &ip);
	void Remove		(uint32_t id);

private:
	std::vector<Warehouse> m_warehouses;
};

#endif // WAREHOUSETABLE_H
