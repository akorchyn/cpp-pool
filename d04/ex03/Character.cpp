#include "Character.hpp"

Character::Character(std::string const &name) : _size(0), _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

std::string const &Character::getName() const
{
	return _name;
}

Character::Character(Character const &x) : _size(x._size), _name(x._name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = (x._inventory[i]) ? x._inventory[i]->clone() : NULL;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}

Character &Character::operator=(Character const &x)
{
	if (&x == this)
		return *this;
	_name = x._name;
	_size = x._size;
	for (int i = 0; i < 4; i++)
	{
		delete _inventory[i];
		_inventory[i] = (x._inventory[i]) ? x._inventory[i]->clone() : NULL;
	}
	return *this;
}

void Character::equip(AMateria *m)
{
	if (_size == 4 || !m)
		return ;
	for (int i = 0; i < 4; i++)
		if (!_inventory[i])
		{
			_inventory[i] = m;
			break ;
		}
	_size++;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || !_inventory[idx])
		return ;
	_inventory[idx] = NULL;
	_size--;
}

void Character::use(int id, ICharacter &target)
{
	if (id > 3 || id < 0 || !_inventory[id])
		return ;
	_inventory[id]->use(target);
}
