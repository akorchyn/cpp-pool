#include "../includes/Print.hpp"

Print::Print()
{
}

Print::Print(Print const &x)
{
	*this = x;
}

Print &Print::operator=(Print const __attribute__((unused))&x)
{
	return *this;
}

Print::~Print()
{
}

void Print::execute(std::vector<char>::iterator &x,
					__attribute__((unused))std::list<IOperation *>::iterator &queue) const
{
	std::cout << *x;
}

IOperation * Print::clone()
{
	return (new Print);
}
