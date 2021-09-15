#ifndef WAREHOUSEAPI_H
#define WAREHOUSEAPI_H

#include "BaseApi.h"

class WarehouseApi : public BaseApi
{
public:
	using BaseApi::BaseApi;
private:
	void HandleControl() override final;
};

#endif // WAREHOUSEAPI_H
