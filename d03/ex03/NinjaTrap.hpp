#ifndef HELPER_NINJATRAP_HPP
#define HELPER_NINJATRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
private:
	NinjaTrap();
	
public:
	NinjaTrap(const std::string &name);
	NinjaTrap(const NinjaTrap &x);
	~NinjaTrap();
	NinjaTrap &operator=(const NinjaTrap &x);

	void	rangedAttack(const std::string &target) const;
	void	meleeAttack(const std::string &target) const;
	void	takeDamage(unsigned amount);
	void	toRepaired(unsigned amount);
	void	ninjaShoebox(FragTrap &target) const;
	void	ninjaShoebox(ScavTrap &target) const;
};


#endif
