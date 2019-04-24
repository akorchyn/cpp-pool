#include "FragTrap.hpp"

FragTrap::FragTrap()
{
}

FragTrap::FragTrap(const std::string &_name)
: _hp(100), _energy(100), _lvl(1), _name(_name), _meleeAttackDamage(30), _rangedAttackDamage(20), _armorReduction(5)
{
	std::srand(time(NULL));
	std::cout << "I'm constructed. My _name is " << _name << " . I am ready to fight" << std::endl;
}

FragTrap::FragTrap(const FragTrap &x)
{
	std::srand(time(NULL));
	*this = x;
	std::cout << "I'm constructed. I am prototype to " << _name << " bot. I am ready to fight" << std::endl;

}

FragTrap &FragTrap::operator=(const FragTrap &x)
{
	std::cout << "Starting process copying a bot with _name " << x._name << " ..." << std::endl << "...\n...\nFinished. Ready to fight" << std::endl;
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

FragTrap::~FragTrap()
{
	std::cout << "** Confirming the bot " << _name << " destroyed. Sending rotation... **" << std::endl;
}

void FragTrap::rangedAttack(const std::string &target) const
{
	std::cout << "See a target " << target << ". Unlocked the fuse. Aiming... Wind correction... Waiting for confirmation" << std::endl;
	std::cout << "** Confirming " << _name << ". Fire! **" << std::endl;
	std::cout << "Hit it. My sensors show " << _rangedAttackDamage << " damage." << std::endl;
	std::cout << "** Finish him and act according to plan **" << std::endl;
}

void FragTrap::meleeAttack(const std::string &target) const
{
	std::cout << "I got close to " << target << ". Hitting. *Blow sound* Successful hit. My sensors show " << _meleeAttackDamage << " damage" << std::endl;
	std::cout << "** Confirming " << _name << ". Act according to plan **" << std::endl;
}

void FragTrap::takeDamage(unsigned amount)
{
	int		damage;

	damage = amount - _armorReduction;
	if (damage < 0)
		damage = 0;
	if (_hp - damage <= 0)
	{
		std::cout << "I take a lethal damage.. I am des...tro..." << std::endl;
		_hp = 0;
	}
	else
	{
		_hp -= damage;
		std::cout << "I was shot. Preliminary estimate more than " << damage / 2 << " damage" << std::endl;
		std::cout << "Starting detailed scanning...\n...\n" << "Oh, is so much worse... " << damage << " damage." << std::endl;
		std::cout << "** Confirming, be careful... **" << std::endl;
	}
}

void FragTrap::toRepaired(unsigned amount)
{
	if (_hp + amount > _maxHitPoints)
	{
		_hp = _maxHitPoints;
		std::cout << "All system works good. Successful repairing" << std::endl;
	}
	else
	{
		_hp += amount;
		std::cout << "Fixed some systems. Current status " << _hp << "/" << _maxHitPoints << std::endl;
	}
}

void FragTrap::vaulthunter_dot_exe(const std::string &target)
{
	_energy -= 25;
	if (_energy < 0)
	{
		std::cout << "Damn. My _energy is low. I can't do anything. " + target + " is unharmed" << std::endl;
		_energy = 0;
		return ;
	}
	const std::string	phrases[] = {
			std::string("Hyah, heyaaah, take that. I am god. I kill you ") + target + " by next attack...\n",
			std::string("Bop. Yahooooo, take it little pony. ") + target + " get a lot of kick-ass\n",
			std::string("Your mom is fat. ") + target + " got a psychological trauma\n",
			std::string("I better then you. Why ? Because, you're dying. Ha-ha-ha-ha. ") + target + " doesn't understand.\n",
			std::string("Hey, ") + target + " do u no da way? " + target + " felt his superiority and then a kick-ass\n",
			std::string(target) + " do you believe god? Then, lets speak about our lord Poseidon. " + target + " run like hell.\n"
	};
	int n = std::rand() % 6;
	std::cout << phrases[n];
}
