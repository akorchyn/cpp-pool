#ifndef HELPER_ZOMBIE_HPP
#define HELPER_ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string		_name;
	std::string		_type;

public:
	Zombie(std::string name, std::string type);
	void	announce() const;
	~Zombie();
};


#endif
