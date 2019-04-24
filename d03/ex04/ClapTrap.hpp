#ifndef HELPER_CLAPTRAP_HPP
#define HELPER_CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
protected:
	int			_hp;
	unsigned	_maxHpPoint;
	int 		_energy;
	unsigned 	_maxEnergyPoint;
	int 		_lvl;
	std::string _name;
	int 		_meleeAttackDamage;
	int 		_rangedAttackDamage;
	int 		_armorReduction;

	ClapTrap();
	ClapTrap(const std::string &name, int _hp, int max_hp, int max_energy, int _energy, int _lvl, int meleeAttackDamage, int rangedAttackDamage, int armor);
	ClapTrap(const ClapTrap &x);
	~ClapTrap();

	ClapTrap	&operator=(const ClapTrap &orig);

public:
	const std::string &get_name() const;

};

#endif