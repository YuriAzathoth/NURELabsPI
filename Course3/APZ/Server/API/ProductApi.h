#ifndef PRODUCTAPI_H
#define PRODUCTAPI_H

#include "BaseApi.h"

class ProductApi : public BaseApi
{
public:
	using BaseApi::BaseApi;
private:
	void HandleControl() override final;
};

#endif // PRODUCTAPI_H
