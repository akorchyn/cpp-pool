#ifndef HELPER_HUMANA_HPP
#define HELPER_HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
	Weapon &_x;
	std::string _name;

public:
	HumanA(const std::string &name, Weapon &x);
	void attack();
};


#endif
