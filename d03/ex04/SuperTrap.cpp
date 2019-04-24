#include "SuperTrap.hpp"

SuperTrap::SuperTrap()
{
}

SuperTrap::SuperTrap(const std::string &name)
	: ClapTrap(name, 100, 100, 120, 120, 1, 60, 20, 5), FragTrap(name), NinjaTrap(name)

{
	std::cout << "Super bot is constructed. I am ready to destroying." << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap &x)
: ClapTrap(x), FragTrap(x.get_name()), NinjaTrap(x.get_name())
{
	std::cout << "Constructing SUPER TRAP FROM " << x.get_name() << std::endl;
}

SuperTrap &SuperTrap::operator=(const SuperTrap &x)
{
	if (this == &x)
		return *this;
	std::cout << "I copying from " << x.get_name() << std::endl;
	std::cout << "Finished" << std::endl;
	ClapTrap::operator=(x);
	return *this;
}

void SuperTrap::rangedAttack(const std::string &target) const
{
	FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(const std::string &target) const
{
	NinjaTrap::meleeAttack(target);
}

SuperTrap::~SuperTrap()
{
	std::cout << "THE UNION SUPER TRAP DEFEAT. WE HAVE A LOT OF PROBLEM" << std::endl;
}

void SuperTrap::takeDamage(unsigned amount)
{
	NinjaTrap::takeDamage(amount);
}

void SuperTrap::toRepaired(unsigned amount)
{
	FragTrap::toRepaired(amount);
}
