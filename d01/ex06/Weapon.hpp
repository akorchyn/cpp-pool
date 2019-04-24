#ifndef HELPER_WEAPON_HPP
#define HELPER_WEAPON_HPP

#include <string>

class Weapon
{
private:
	std::string _type;

public:
	Weapon(const std::string &weapon);
	const std::string &get_type() const;
	void setType(const std::string &_type);
};


#endif
