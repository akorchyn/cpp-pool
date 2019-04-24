#ifndef HELPER_FRAGTRAP_HPP
#define HELPER_FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>
#include <random>

class FragTrap : virtual public ClapTrap
{
protected:
	FragTrap();

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
