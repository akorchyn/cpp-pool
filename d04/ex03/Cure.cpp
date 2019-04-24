#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(Cure const &x) : AMateria(x)
{
}

Cure &Cure::operator=(Cure const &x)
{
	if (&x == this)
		return *this;
	AMateria::operator=(x);
	return *this;
}

Cure::~Cure()
{
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	AMateria::use(target);
}

AMateria *Cure::clone() const
{
	return new Cure;
}
