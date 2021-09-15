#ifndef IPRINTABLE_H
#define IPRINTABLE_H


class IPrintable
{
public:
	virtual ~IPrintable() {}
	virtual void Print() const = 0;
};

#endif // IPRINTABLE_H
