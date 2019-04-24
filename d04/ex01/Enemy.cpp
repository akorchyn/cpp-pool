#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const &type) : _type(type), _hp(hp)
{
}

Enemy &Enemy::operator=(Enemy const &x)
{
	if (&x == this)
		return *this;
	_type = x._type;
	_hp = x._hp;
	return *this;
}

Enemy::Enemy(Enemy const &x)
{
	*this = x;
}

Enemy::~Enemy()
{
}

std::string const &Enemy::getType() const
{
	return _type;
}

int Enemy::getHP() const
{
	return _hp;
}

void Enemy::takeDamage(int x)
{
	if (x < 0)
		return ;
	_hp -= x;
}
