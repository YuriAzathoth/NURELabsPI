#ifndef GOODSTABLE_H
#define GOODSTABLE_H

#include "Shared/IObject.h"
#include "Web/ICookieDependentObject.h"
#include "Product.h"

class ProductTable : public IObject, public ICookieDependentObject
{
public:
	enum class EScope { USER, WAREHOUSE };

	ProductTable(ServerContext* global_context, CookiesManager &cookies) : IObject(global_context), ICookieDependentObject(cookies) {}

	const std::vector<Product> &Get() const noexcept { return m_products; }

	void Calc	(std::string cat_name, uint16_t count, std::string user_token);
	void Create	(std::string ware_name, std::string cat_name, uint16_t count, std::string user_token);
	void Create	(uint32_t ware_id, std::string cat_name, uint16_t count, std::string user_token);
	void Load	();
	void Load	(EScope scope, uint32_t id);
	void Remove	(uint32_t id);

private:
    void LoadData(const std::string &statement);

	std::vector<Product> m_products;
};

#endif // GOODSTABLE_H
