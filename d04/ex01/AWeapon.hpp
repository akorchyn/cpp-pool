#ifndef HELPER_AWEAPON_HPP
#define HELPER_AWEAPON_HPP

#include <string>

class AWeapon
{
private:
	std::string _name;
	int			_ap;
	int 		_damage;

public:
	AWeapon(std::string const &name, int apcost, int damage);
	AWeapon(AWeapon const &x);
	AWeapon &operator=(AWeapon const &x);
	virtual ~AWeapon();

	std::string const &getName() const;
	int getAPCost() const;
	int getDamage() const;

	virtual void	attack() const = 0;
};


#endif
