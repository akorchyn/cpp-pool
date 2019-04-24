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
	Zombie();
	void announce() const;
	void set_type(const std::string &_type);
	void set_name(const std::string &_name);
	~Zombie();
};


#endif //HELPER_ZOMBIE_HPP
