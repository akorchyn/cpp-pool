#ifndef HELPER_PLASMARIFLE_HPP
#define HELPER_PLASMARIFLE_HPP

#include "AWeapon.hpp"
#include <iostream>

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle();
	~PlasmaRifle();
	PlasmaRifle(PlasmaRifle const &x);
	PlasmaRifle &operator=(PlasmaRifle const &x);

	void attack() const;
};

#endif
