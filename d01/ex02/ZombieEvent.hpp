#ifndef HELPER_ZOMBIEEVENT_HPP
#define HELPER_ZOMBIEEVENT_HPP

#include <string>
#include <iostream>
#include "Zombie.hpp"
#include <random>

class ZombieEvent
{
private:
	std::string		_type;
	std::string		_randomName();

public:
	void		setType(const std::string &type);
	Zombie		*newZombie(std::string name);
	Zombie		*randomChump();
};


#endif