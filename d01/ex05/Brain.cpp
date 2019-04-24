#include "Brain.hpp"

std::string Brain::identify() const
{
	std::stringstream k;
	k << this;
	return (k.str());
}
