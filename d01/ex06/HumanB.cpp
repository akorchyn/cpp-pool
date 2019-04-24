//
// Created by Artur-yurii KORCHYNSKYI on 2019-03-12.
//

#include "HumanB.hpp"

void HumanB::set_x(Weapon *_x)
{
	HumanB::_x = _x;
}

HumanB::HumanB(const std::string &name) : _x(NULL), _name(name)
{
}

void HumanB::attack()
{
	std::cout << _name << " attacks with his " << _x->get_type() << std::endl;
}
