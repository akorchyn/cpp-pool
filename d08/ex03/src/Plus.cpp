#include "../includes/Plus.hpp"

Plus::Plus()
{
}


Plus::Plus(Plus const &x)
{
	*this = x;
}

Plus &Plus::operator=(Plus const __attribute__((unused)) &x)
{
	return *this;
}

Plus::~Plus()
{
}

void Plus::execute(std::vector<char>::iterator &x,
				   __attribute__((unused))std::list<IOperation *>::iterator &queue) const
{
	(*x)++;
}

IOperation * Plus::clone()
{
	return (new Plus);
}
