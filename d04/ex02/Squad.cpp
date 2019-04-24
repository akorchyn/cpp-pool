#include "Squad.hpp"

int Squad::getCount() const
{
	return _size;
}

Squad::Squad()
	: _size(0), _squad(NULL)
{
}

Squad::Squad(Squad const &x)
	: _size(x._size), _squad(new ISpaceMarine *[x._size])
{
	for (int i = 0; i < _size; i++)
		_squad[i] = x._squad[i]->clone();
}

Squad &Squad::operator=(Squad const &x)
{
	if (&x == this)
		return *this;
	ISpaceMarine **tmp = new ISpaceMarine *[x._size];
	delete [] _squad;
	_squad = tmp;
	for (int i = 0; i < _size; i++)
		_squad[i] = x._squad[i]->clone();
	return *this;
}

ISpaceMarine *Squad::getUnit(int x) const
{
	if (x >= _size || x < 0)
		return NULL;
	return _squad[x];
}

int Squad::push(ISpaceMarine *x)
{
	for (int i = 0; i < _size; i++)
		if (!x || x == _squad[i])
			return _size;

	ISpaceMarine **tmp = new ISpaceMarine *[++_size];
	for (int i = 0; i < _size - 1; i++)
		tmp[i] = _squad[i];
	delete [] _squad;
	_squad = tmp;
	_squad[_size - 1] = x;
	return _size;
}

Squad::~Squad()
{
	for (int i = 0; i < _size; i++)
		delete _squad[i];
	delete [] _squad;
}
