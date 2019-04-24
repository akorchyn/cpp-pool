#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(Ice const &x) : AMateria(x)
{
}

Ice &Ice::operator=(Ice const &x)
{
	if (&x == this)
		return *this;
	AMateria::operator=(x);
	return *this;
}

Ice::~Ice()
{
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	AMateria::use(target);
}

AMateria *Ice::clone() const
{
	return new Ice;
}
