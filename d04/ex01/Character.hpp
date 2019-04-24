#ifndef HELPER_CHARACTER_HPP
#define HELPER_CHARACTER_HPP

#include "Enemy.hpp"
#include "AWeapon.hpp"
#include <string>
#include <iostream>

class Character
{
private:
	std::string _name;
	int 		_ap;
	AWeapon		*_gun;

public:
	Character(std::string const &name);
	Character(Character const &x);
	~Character();

	std::string const	&getName() const;
	int					getAp() const;
	AWeapon 			*getGun() const;

	Character &operator=(Character const &x);

	void				recoverAP();
	void				equip(AWeapon*);
	void				attack(Enemy*);
};

std::ostream	&operator<<(std::ostream &s, Character const &x);

#endif
