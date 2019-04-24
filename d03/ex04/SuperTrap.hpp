#ifndef HELPER_SUPERTRAP_HPP
#define HELPER_SUPERTRAP_HPP

#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
#include "FragTrap.hpp"

class SuperTrap
		: public FragTrap,
		  public NinjaTrap
{
private:
	SuperTrap();
	
public:
	SuperTrap(const std::string &name);
	SuperTrap(const SuperTrap &x);
	SuperTrap &operator=(const SuperTrap &x);
	~SuperTrap();
	void	rangedAttack(const std::string &target) const;
	void	meleeAttack(const std::string &target) const;
	void	takeDamage(unsigned amount);
	void	toRepaired(unsigned amount);
};


#endif
