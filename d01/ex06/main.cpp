#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

int main()
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB bob("bob");
		bob.set_x(&club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
}