#ifndef CATEGORYAPI_H
#define CATEGORYAPI_H

#include "BaseApi.h"

class CategoryApi : public BaseApi
{
public:
	using BaseApi::BaseApi;
private:
	void HandleControl() override final;
};

#endif // CATEGORYAPI_H
