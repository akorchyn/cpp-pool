#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap()
{
}

NinjaTrap::NinjaTrap(const std::string &name)
	: ClapTrap(name, 60, 60, 120, 120, 1, 60, 5, 0)
{
	std::cout << "You don't see me, but ninja already is here." << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &x)
	: ClapTrap(x)
{
	std::cout << "I new ninja. My master is " << x._name << std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "Oh, no i defeat." << std::endl;
}

NinjaTrap &NinjaTrap::operator=(const NinjaTrap &x)
{
	std::cout << "I learn new style from " << x._name << std::endl;
	if (&x == this)
		return *this;
	ClapTrap::operator=(x);
	return *this;
}

void NinjaTrap::rangedAttack(const std::string &target) const
{
	std::cout << "I throw kunai to " << target << ". " << _rangedAttackDamage << " damage" << std::endl;
}

void NinjaTrap::meleeAttack(const std::string &target) const
{
	std::cout << "I am a shadow. Ninja " << _name << " is here. Look at me " << target << "\n*stab by blade*\n"
			<< _meleeAttackDamage << " damage" << std::endl;
}

void NinjaTrap::takeDamage(unsigned amount)
{
	int damage = amount - _armorReduction;

	if (damage < 0)
		damage = 0;
	if (_hp - damage <= 0)
	{
		_hp = 0;
		std::cout << "Oh, no, I am dying" << std::endl;
	}
	else
	{
		_hp -= damage;
		std::cout << "My opponent is good. I take " << damage << " damage" << std::endl;
	}
}

void NinjaTrap::toRepaired(unsigned amount)
{
	_hp += amount;
	if (_hp + amount >= _maxHpPoint)
	{
		_hp = _maxHpPoint;
		std::cout << "I am fully healed" << std::endl;
	}
	else
		std::cout << "I need a bandage. I use it. Hooh... " << _hp << "/" << _maxHpPoint << " hp" << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap &target) const
{
	std::cout << "Obscure kunai. It kill a lot of people and bots. " << target.get_name() << " is one of them" << std::endl;
	target.takeDamage(_meleeAttackDamage);
}

void NinjaTrap::ninjaShoebox(ScavTrap &target) const
{
	std::cout << "Smoke bomb. He use it and " << target.get_name() << " go blind, then quick hit and he fall" << std::endl;
	target.takeDamage(_meleeAttackDamage);
}
