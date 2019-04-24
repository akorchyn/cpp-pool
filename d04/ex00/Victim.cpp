#include "Victim.hpp"

Victim::Victim(const std::string name) : _name(name)
{
	std::cout << "Some random victim called " << _name << " just popped !" << std::endl;
}

Victim::Victim(const Victim &x)
{
	*this = x;
	std::cout << "Some random victim called " << _name << " just popped !" << std::endl;
}

Victim &Victim::operator=(const Victim &x)
{
	if (&x == this)
		return *this;
	_name = x._name;
	return *this;
}

Victim::~Victim()
{
	std::cout << "Victim " << _name << " just died for no apparent reason !" << std::endl;
}

std::ostream &operator<<(std::ostream &s, const Victim &x)
{
	s << "I'm " << x.get_name() << " and I like otters !" << std::endl;
	return s;
}

const std::string &Victim::get_name() const
{
	return _name;
}

void Victim::getPolymorphed() const
{
	std::cout << _name << " has been turned into a cute little sheep !" << std::endl;
}
