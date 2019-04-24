#ifndef HELPER_ZOMBIEHORDE_HPP
#define HELPER_ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde
{
private:
	Zombie	*_horde;
	int 	_size;

	std::string		_randomName();
public:
	ZombieHorde(int x);
	void	announce(void);
	~ZombieHorde();
};


#endif //HELPER_ZOMBIEHORDE_HPP
