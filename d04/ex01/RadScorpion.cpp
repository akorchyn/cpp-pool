#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion")
{
	std::cout <<  "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const &x) : Enemy(x)
{
	std::cout <<  "* click click click *" << std::endl;
}

RadScorpion &RadScorpion::operator=(RadScorpion const &x)
{
	if (&x == this)
		return *this;
	Enemy::operator=(x);
	return *this;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}
