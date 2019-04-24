#include "../includes/PrevElement.hpp"

PrevElement::PrevElement()
{
}

PrevElement::PrevElement(PrevElement const &x)
{
	*this = x;
}

PrevElement &PrevElement::operator=(PrevElement const __attribute__((unused)) &x)
{
	return *this;
}

PrevElement::~PrevElement()
{
}

void PrevElement::execute(std::vector<char>::iterator &x,
						  __attribute__((unused))std::list<IOperation *>::iterator &queue) const
{
	x--;
}

IOperation * PrevElement::clone()
{
	return (new PrevElement);
}
