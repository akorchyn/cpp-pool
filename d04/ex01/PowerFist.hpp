#ifndef HELPER_POWERFIST_HPP
#define HELPER_POWERFIST_HPP

#include <iostream>
#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
	PowerFist();
	PowerFist(PowerFist const &x);
	~PowerFist();
	PowerFist &operator=(PowerFist const &x);

	void	attack() const;
};


#endif
