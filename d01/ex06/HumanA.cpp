//
// Created by Artur-yurii KORCHYNSKYI on 2019-03-12.
//

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &x) : _x(x), _name(name)
{
}

void HumanA::attack()
{
	std::cout << _name << " attacks with his " << _x.get_type() << std::endl;
}
