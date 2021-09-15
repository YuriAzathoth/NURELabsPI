#include "PCH.h"
#include "BaseRequestFactory.h"
#include "Shared/ServerContext.h"

std::shared_ptr<ServerContext> g_context;

BaseRequestFactory::BaseRequestFactory()
{
	m_context = new ServerContext;
}

BaseRequestFactory::~BaseRequestFactory()
{
	delete m_context;
}
