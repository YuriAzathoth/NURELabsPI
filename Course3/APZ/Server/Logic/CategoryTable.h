#ifndef CATEGORYTABLE_H
#define CATEGORYTABLE_H

#include "Shared/IObject.h"
#include "Category.h"

class CategoryTable : public IObject
{
public:
	CategoryTable(ServerContext* global_context);
	const std::vector<Category> &Get() const noexcept { return m_categories; }

	void Register	(std::string name, float tmin, float tmax, uint8_t hmin, uint8_t hmax, uint16_t space);
	void Remove		(uint32_t id);

private:
	std::vector<Category> m_categories;
};

#endif // CATEGORYTABLE_H
