#ifndef IOBJECT_H
#define IOBJECT_H

class ServerContext;

class IObject
{
public:
	IObject(ServerContext* global_context) : m_global_context(global_context) {}
protected:
	ServerContext* GetContext() noexcept { return m_global_context; }
private:
	ServerContext* m_global_context;
};

#endif // IOBJECT_H
