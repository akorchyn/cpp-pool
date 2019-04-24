#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &name, int apcost, int damage)
	: _name(name), _ap(apcost), _damage(damage)
{

}

AWeapon &AWeapon::operator=(AWeapon const &x)
{
	if (&x == this)
		return *this;
	_damage = x._damage;
	_ap = x._ap;
	_name = x._name;
	return *this;
}

AWeapon::AWeapon(AWeapon const &x)
{
	*this = x;
}

AWeapon::~AWeapon()
{}

std::string const &AWeapon::getName() const
{
	return _name;
}

int AWeapon::getAPCost() const
{
	return _ap;
}

int AWeapon::getDamage() const
{
	return _damage;
}
