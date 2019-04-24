#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type)
{}

Zombie::~Zombie()
{
	std::cout << "Mghhhff...." << std::endl;
};

void	Zombie::announce() const
{
	std::cout << "<" << _name << " (" << _type << ")> Braiiiiiiiinnnnssss" << std::endl;
}