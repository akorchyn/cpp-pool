#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
}

ScavTrap::ScavTrap(const std::string &_name)
		: _hp(_maxHitPoints), _energy(_maxEnergyPoints), _lvl(1), _name(_name), _meleeAttackDamage(20), _rangedAttackDamage(15), _armorReduction(3)
{
	std::srand(time(NULL));
	std::cout << "My _name is " << _name << " . Lets create future" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &x)
{
	std::srand(time(NULL));
	*this = x;
	std::cout << "Constructing complete. Constructing from  " << _name << " bot." << std::endl;

}

ScavTrap &ScavTrap::operator=(const ScavTrap &x)
{
	std::cout << "Starting process copying a bot with name " << x._name << ". Finishing for a minute. Success." << std::endl;
	if (&x == this)
		return (*this);
	_hp = x._hp;
	_energy = x._energy;
	_lvl = x._lvl;
	_name = x._name;
	_meleeAttackDamage = x._meleeAttackDamage;
	_rangedAttackDamage = x._rangedAttackDamage;
	_armorReduction = x._armorReduction;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "I am " << _name << " and i am dying" << std::endl;
}

void ScavTrap::rangedAttack(const std::string &target) const
{
	std::cout << "*Shooting sound* " << target << " is damaged for " << _rangedAttackDamage << ". " << _name << " triumphs" << std::endl;
}

void ScavTrap::meleeAttack(const std::string &target) const
{
	std::cout << "Enemy is near. Change attack mode to melee. Completed. Attacking. " << target << " blocked attack. ";
	std::cout << "Try again. Failure. Speeding up. Attacking. Success, " << target << " is hited for " << _meleeAttackDamage << std::endl;
}

void ScavTrap::takeDamage(unsigned amount)
{
	int		damage;

	damage = amount - _armorReduction;
	if (damage < 0)
		damage = 0;
	if (_hp - damage <= 0)
	{
		std::cout << _name << " body doesn't work. Lethal damage." << std::endl;
		_hp = 0;
	}
	else
	{
		_hp -= damage;
		std::cout << "I'm hurt. Trying to avoid or minimize damage. Success. Current status : " << _hp << "/" << _maxHitPoints << std::endl;
	}
}

void ScavTrap::toRepaired(unsigned amount)
{
	if (_hp + amount > _maxHitPoints)
	{
		_hp = _maxHitPoints;
		std::cout << "I fully repaired. Ready to action" << std::endl;
	}
	else
	{
		_hp += amount;
		std::cout << "Trying to fix systems. Partial success. Current status :  " << _hp << "/" << _maxHitPoints << std::endl;
	}
}

void ScavTrap::challengeNewcomer(const std::string &target)
{
	_energy -= 25;
	if (_energy < 0)
	{
		std::cout << "Haven't enough energy. " + target + " isn't tested" << std::endl;
		_energy = 0;
		return ;
	}
	const std::string	phrases[] = {
			std::string("Water challenge. Drink all water on planet, ") + target + ", or would be destroyed...\n",
			std::string("Earth challenge. My fantasy end here, ") + target + " do something please\n",
			std::string("Dance battle. Now. HERE! ") + target + " accepting\n",
			std::string("NEW F*****g challenge. You try to still alive. ") + target + " some scared.\n",
			std::string(target) + " what about a challenge? Then, lets i drop you into the river. And you try to save yourself. Winner get nothing. " + target + " run like hell.\n"
	};
	int n = std::rand() % 5;
	std::cout << phrases[n];
}
