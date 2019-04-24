#include "../includes/Minus.hpp"

Minus::Minus()
{
}

Minus::Minus(Minus const &x)
{
	*this = x;
}

Minus &Minus::operator=(Minus const __attribute__((unused)) &x)
{
	return *this;
}

Minus::~Minus()
{
}

void Minus::execute(std::vector<char>::iterator &x,
					__attribute__((unused)) std::list<IOperation *>::iterator &queue) const
{
	(*x)--;
}

IOperation * Minus::clone()
{
	return (new Minus);
}
