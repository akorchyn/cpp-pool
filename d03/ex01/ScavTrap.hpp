#ifndef HELPER_SCAVTRAP_HPP
#define HELPER_SCAVTRAP_HPP

#include <string>
#include <iostream>

class ScavTrap
{
	ScavTrap();
	static const int _maxHitPoints = 100;
	static const int _maxEnergyPoints = 50;

	int			_hp;
	int 		_energy;
	int 		_lvl;
	std::string	_name;
	int 		_meleeAttackDamage;
	int 		_rangedAttackDamage;
	int 		_armorReduction;

public:
	ScavTrap(const std::string &_name);
	ScavTrap(const ScavTrap &x);
	ScavTrap &operator=(const ScavTrap &x);
	~ScavTrap();

	void	rangedAttack(const std::string &target) const;
	void	meleeAttack(const std::string &target) const;
	void	takeDamage(unsigned amount);
	void	toRepaired(unsigned amount);
	void	challengeNewcomer(const std::string &target); // NEED TO CREATE PHRASES
};


#endif
