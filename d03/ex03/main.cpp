#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include <string>

int main()
{
	{
		std::cout << "_____________________________________ FRAG TRAP START"
				  << std::endl;
		FragTrap x("Demonic");
		FragTrap z("Sleepy owl");
		FragTrap y(x);

		x.rangedAttack("cowboy Jim");
		y = z;
		y.meleeAttack("sheep");
		x.takeDamage(65);
		x.toRepaired(35);
		y.toRepaired(55);
		x.vaulthunter_dot_exe("alcoholic");
		x.vaulthunter_dot_exe("drugs dealer");
		x.vaulthunter_dot_exe("reflection");
		y.vaulthunter_dot_exe("kovbasa");
		x.vaulthunter_dot_exe("'author of this bullshit'");
		y.vaulthunter_dot_exe("Happy and lazy programmer");
		x.vaulthunter_dot_exe("Immortal");
		x.takeDamage(1000);
	}
	std::cout << "_____________________________________ FRAG TRAP END" 	 << std::endl;
	{
		std::cout << "_____________________________________ SCAV TRAP START"
				  << std::endl;
		ScavTrap x("Demonic");
		ScavTrap z("Sleepy owl");
		ScavTrap y(x);

		x.rangedAttack("cowboy Jim");
		y = z;
		y.meleeAttack("sheep");
		x.takeDamage(65);
		x.toRepaired(35);
		y.toRepaired(55);
		x.challengeNewcomer("alcoholic");
		y.challengeNewcomer("kovbasa");
		x.challengeNewcomer("'author of this bullshit'");
		y.challengeNewcomer("Happy and lazy programmer");
		x.challengeNewcomer("Immortal");
		x.takeDamage(1000);
	}
	std::cout << "_____________________________________ SCAV TRAP END" << std::endl;
	{
		std::cout << "_____________________________________ NINJA TRAP START" << std::endl;
		ScavTrap x("First");
		FragTrap y("Second");
		NinjaTrap w("Demonic");
		NinjaTrap z("Andrey");
		NinjaTrap f(w);

		w.meleeAttack("cowboy Jim");
		w.rangedAttack("sheep");
		z = w;
		z.takeDamage(35);
		z.takeDamage(55);
		z.toRepaired(34);
		z.toRepaired(150);
		z.ninjaShoebox(x);
		z.ninjaShoebox(y);
	}
	std::cout << "_____________________________________ NINJA TRAP END" << std::endl;
}