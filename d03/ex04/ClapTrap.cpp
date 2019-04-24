#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(const std::string &name, int _hp, int max_hp, int max_energy, int _energy, int _lvl,
				   int meleeAttackDamage, int rangedAttackDamage, int armor)
   : _hp(_hp), _maxHpPoint(max_hp), _energy(_energy), _maxEnergyPoint(max_energy), _lvl(_lvl), _name(name), _meleeAttackDamage(meleeAttackDamage),
   		_rangedAttackDamage(rangedAttackDamage), _armorReduction(armor)

{
	std::cout << "The body succesfully constructed for " << name << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap &x)
{
	*this = x;
	std::cout << x._name << " is construction model." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Body is destroyed.... Pshhhhhhhh, " << _name << " explodes" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &orig)
{
	std::cout << "Copying is started. Modification.... Completed..." << std::endl;
	if (this == &orig)
		return (*this);
	_hp = orig._hp;
	_maxHpPoint = orig._maxHpPoint;
	_maxEnergyPoint = orig._maxEnergyPoint;
	_energy = orig._energy;
	_armorReduction = orig._armorReduction;
	_name = orig._name;
	_meleeAttackDamage = orig._meleeAttackDamage;
	_rangedAttackDamage = orig._rangedAttackDamage;
	_lvl = orig._lvl;
	return (*this);
}

const std::string &ClapTrap::get_name() const
{
	return _name;
}
