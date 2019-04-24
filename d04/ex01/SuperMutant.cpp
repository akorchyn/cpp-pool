#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &x) : Enemy(x)
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant &SuperMutant::operator=(SuperMutant const &x)
{
	if (&x == this)
		return *this;
	Enemy::operator=(x);
	return *this;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh ..." << std::endl;
}

void SuperMutant::takeDamage(int n)
{
	Enemy::takeDamage(n - 3);
}
