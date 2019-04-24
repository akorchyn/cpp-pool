#include "Weapon.hpp"

const std::string &Weapon::get_type() const
{
	return _type;
}

Weapon::Weapon(const std::string &weapon) : _type(weapon)
{
}

void Weapon::setType(const std::string &_type)
{
	Weapon::_type = _type;
}
