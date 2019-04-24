#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _size(0)
{
}

MateriaSource::MateriaSource(MateriaSource const &x) : _size(x._size)
{
	for (int i = 0; i < _size; i++)
		_store[i] = x._store[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource const &x)
{
	if (&x == this)
		return *this;
	for (int i = 0; i < _size; i++)
		delete _store[i];
	_size = x._size;
	for (int i = 0; i < _size; i++)
		_store[i] = x._store[i]->clone();
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < _size; i++)
		delete _store[i];
}

void MateriaSource::learnMateria(AMateria *x)
{
	if (_size == 4)
		return ;
	_store[_size++] = x;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < _size; i++)
		if (_store[i]->getType() == type)
			return _store[i]->clone();
	return NULL;
}

