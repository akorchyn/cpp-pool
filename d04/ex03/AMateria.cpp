#include "AMateria.hpp"

AMateria::AMateria(std::string const &x) : _xp(0), _type(x)
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria(AMateria const &x) : _xp(x._xp), _type(x._type)
{
}

AMateria &AMateria::operator=(AMateria const &x)
{
	if (&x == this)
		return *this;
	_xp = x._xp;
	return *this;
}

void AMateria::use(ICharacter &target)
{
	static_cast<void>(target);
	_xp += 10;
}

std::string const &AMateria::getType()
{
	return _type;
}

unsigned int AMateria::getXP()
{
	return _xp;
}
