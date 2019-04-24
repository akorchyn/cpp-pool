#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int x) : _horde(new Zombie[x]), _size(x)
{
	srand(time(NULL));
	for (int i = 0; i < x; i++)
	{
		_horde[i].set_name(_randomName());
		_horde[i].set_type("Horde zombie");
	}
}

std::string		ZombieHorde::_randomName()
{
	std::string result = "";
	static const char str[] =
			"abcdefghijklmnopqrstuvwxyz";
	int len = rand() % 29 + 1;
	for (int i = 0; i < len; i++)
		result += str[rand() % (sizeof(str) - 1)];
	result[0] -= 32;
	return (result);
}

ZombieHorde::~ZombieHorde()
{
	std::cout << "Horde destroyed" << std::endl;
	delete []_horde;
}

void ZombieHorde::announce(void)
{
	for (int i = 0; i < _size; i++)
		_horde[i].announce();
}
