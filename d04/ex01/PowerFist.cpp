#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::PowerFist(PowerFist const &x) : AWeapon(x)
{
}

PowerFist::~PowerFist()
{
}

PowerFist &PowerFist::operator=(PowerFist const &x)
{
	if (&x == this)
		return  *this;
	AWeapon::operator=(x);
	return *this;
}

void PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
