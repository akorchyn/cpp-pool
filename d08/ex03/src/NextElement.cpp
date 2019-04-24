#include "../includes/NextElement.hpp"

NextElement::NextElement()
{
}

NextElement::NextElement(NextElement const &x)
{
	*this = x;
}

NextElement &NextElement::operator=(NextElement const __attribute__((unused)) &x)
{
	return *this;
}

NextElement::~NextElement()
{
}

void NextElement::execute(std::vector<char>::iterator &x,
						  __attribute__((unused))std::list<IOperation *>::iterator &queue) const
{
	x++;
}

IOperation * NextElement::clone()
{
	return (new NextElement);
}
