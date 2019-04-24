#include "ZombieEvent.hpp"

void ZombieEvent::setType(const std::string &type)
{
	_type = type;
}

Zombie	*ZombieEvent::newZombie(std::string name)
{
	return new Zombie(name, _type);
}

Zombie *ZombieEvent::randomChump()
{
	Zombie	*x = new Zombie(_randomName(), _type);
	x->announce();
	return (x);
}

std::string ZombieEvent::_randomName()
{
	std::string result = "";
	static const char str[] =
			"abcdefghijklmnopqrstuvwxyz";
	srand(time(NULL));
	int len = rand() % 29 + 1;
	for (int i = 0; i < len; i++)
		result += str[rand() % (sizeof(str) - 1)];
	result[0] -= 32;
	return (result);
}

