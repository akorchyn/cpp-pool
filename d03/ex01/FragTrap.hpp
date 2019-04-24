#ifndef HELPER_FRAGTRAP_HPP
#define HELPER_FRAGTRAP_HPP

#include <string>
#include <iostream>
#include <random>

class FragTrap
{
	FragTrap();
	static const int _maxHitPoints = 100;
	static const int _maxEnergyPoints = 100;

	int			_hp;
	int 		_energy;
	int 		_lvl;
	std::string	_name;
	int 		_meleeAttackDamage;
	int 		_rangedAttackDamage;
	int 		_armorReduction;

public:
	FragTrap(const std::string &_name);
	FragTrap(const FragTrap &x);
	FragTrap &operator=(const FragTrap &x);
	~FragTrap();

	void	rangedAttack(const std::string &target) const;
	void	meleeAttack(const std::string &target) const;
	void	takeDamage(unsigned amount);
	void	toRepaired(unsigned amount);
	void	vaulthunter_dot_exe(const std::string &target);
};


#endif
