#include "../includes/Ignore.hpp"

Ignore::Ignore()
{
}

Ignore::Ignore(Ignore const __attribute__((unused))&x)
{
}

Ignore &Ignore::operator=(Ignore const __attribute__((unused))&x)
{
	return *this;
}

Ignore::~Ignore()
{
}

void Ignore::execute(__attribute__((unused)) std::vector<char>::iterator &x,
					 __attribute__((unused)) std::list<IOperation *>::iterator &queue) const
{
}

IOperation * Ignore::clone()
{
	return new Ignore;
}
