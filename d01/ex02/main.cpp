#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>

int main()
{
	ZombieEvent x;
	x.setType("Water");
	Zombie y("Vasya Pupkin", "Fire");
	y.announce();
	Zombie *z = x.newZombie("Igor Nikitov");
	z->announce();
	x.setType("Earth");
	Zombie *a = x.randomChump();
	delete a;
	delete z;
}
