#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &x) : AWeapon(x)
{
}

PlasmaRifle &PlasmaRifle::operator=(PlasmaRifle const &x)
{
	if (&x == this)
		return  *this;
	AWeapon::operator=(x);
	return *this;
}

PlasmaRifle::~PlasmaRifle()
{
}

void PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
