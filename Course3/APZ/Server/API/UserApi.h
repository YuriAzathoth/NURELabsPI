#ifndef ACCOUNTAPI_H
#define ACCOUNTAPI_H

#include "BaseApi.h"

class UserApi : public BaseApi
{
public:
	using BaseApi::BaseApi;
private:
	void HandleControl() override final;
};

#endif // ACCOUNTAPI_H
