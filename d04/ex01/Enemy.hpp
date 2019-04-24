#ifndef HELPER_ENEMY_HPP
#define HELPER_ENEMY_HPP

#include <string>

class Enemy
{
private:
	std::string _type;
	int 		_hp;

public:
	Enemy(int hp, std::string const &type);
	Enemy(Enemy const &x);
	virtual ~Enemy();

	Enemy &operator=(Enemy const &x);

	std::string const	&getType() const;
	int 				getHP() const;
	virtual void		takeDamage(int);
};

#endif
