#include "FragTrap.hpp"
#include <string>

int main()
{
	FragTrap	x("Demonic");
	FragTrap	z("Sleepy owl");
	FragTrap	y(x);

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