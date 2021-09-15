#ifndef LANGAPI_H
#define LANGAPI_H

#include "BaseApi.h"

class LangApi : public BaseApi
{
public:
	LangApi(ServerContext* context) : BaseApi(context, "") {}
private:
	void HandleControl() override final { m_context->SetL10n(GetFormData("lang")); }
};

#endif // LANGAPI_H
