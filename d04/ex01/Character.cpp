#include "Character.hpp"

Character::Character(std::string const &name) : _name(name), _ap(40), _gun(NULL)
{
}

Character::Character(Character const &x)
{
	*this = x;
}

Character &Character::operator=(Character const &x)
{
	if (&x == this)
		return *this;
	_name = x._name;
	_gun = x._gun;
	_ap = x._ap;
	return *this;
}

const std::string &Character::getName() const
{
	return _name;
}

int Character::getAp() const
{
	return _ap;
}

AWeapon *Character::getGun() const
{
	return _gun;
}

void Character::recoverAP()
{
	_ap += 10;
	if (_ap > 40)
		_ap = 40;
}

void Character::equip(AWeapon *x)
{
	_gun = x;
}

void Character::attack(Enemy *x)
{
	if (!_gun || _ap - _gun->getAPCost() < 0)
		return ;
	_ap -= _gun->getAPCost();
	std::cout << _name << " attacks " << x->getType() <<  " with a " << _gun->getName() << std::endl;
	x->takeDamage(_gun->getDamage());
	_gun->attack();
	if (x->getHP() <= 0)
		delete x;
}

Character::~Character()
{
}

std::ostream &operator<<(std::ostream &s, Character const &x)
{
	s << x.getName() << " has " << x.getAp() << "AP and ";
	if (x.getGun())
		s << "wields a " << x.getGun()->getName();
	else
		s << "is unarmed";
	s << std::endl;
	return s;
}
