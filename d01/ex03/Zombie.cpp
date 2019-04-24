#include "Zombie.hpp"

Zombie::Zombie()
{}

Zombie::~Zombie()
{
	std::cout << "Mghhhff...." << std::endl;
};

void	Zombie::announce() const
{
	std::cout << "<" << _name << " (" << _type << ")> Braiiiiiiiinnnnssss" << std::endl;
}

void Zombie::set_name(const std::string &_name)
{
	Zombie::_name = _name;
}

void Zombie::set_type(const std::string &_type)
{
	Zombie::_type = _type;
}
