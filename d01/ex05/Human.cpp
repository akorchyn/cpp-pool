#include "Human.hpp"

const Brain &Human::getBrain() const
{
	return x;
}

std::string Human::identify()
{
	std::stringstream k;
	k << this;
	return (k.str());
}
