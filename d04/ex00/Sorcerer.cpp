#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title)
	: _name(name), _title(title)
{
	std::cout << name << ", " << title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &x)
{
	*this = x;
	std::cout << _name << ", " << _title << ", is born !" << std::endl;
}

Sorcerer &Sorcerer::operator=(const Sorcerer &x)
{
	if (&x == this)
		return *this;
	_title = x._title;
	_name = x._name;
	return *this;
}

const std::string &Sorcerer::get_name() const
{
	return _name;
}

const std::string &Sorcerer::get_title() const
{
	return _title;
}

Sorcerer::~Sorcerer()
{
	std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same !" << std::endl;
}

std::ostream &operator<<(std::ostream &s, const Sorcerer &x)
{
	s << "I am " << x.get_name() << ", " << x.get_title() << ", and I like ponies !" << std::endl;
	return s;
}

void Sorcerer::polymorph(Victim const &x) const
{
	x.getPolymorphed();
}
