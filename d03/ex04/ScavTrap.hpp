#ifndef HELPER_SCAVTRAP_HPP
#define HELPER_SCAVTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:
	ScavTrap();

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
