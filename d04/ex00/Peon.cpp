#include "Peon.hpp"

Peon::Peon(const std::string &name)
	: Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Peon &x) : Victim(x)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon &Peon::operator=(const Peon &x)
{
	if (&x == this)
		return *this;
	Victim::operator=(x);
	return *this;
}

void Peon::getPolymorphed() const
{
	std::cout << _name << " has been turned into a pink pony !" << std::endl;
}
