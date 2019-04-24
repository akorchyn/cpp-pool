#ifndef HELPER_HUMANB_HPP
#define HELPER_HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	Weapon *_x;
	std::string _name;

public:
	HumanB(const std::string &name);
	void attack();
	void set_x(Weapon *_x);
};

#endif //HELPER_HUMANB_HPP
