#include "Pony.hpp"

int			Pony::getEyes() const
{
	return (_eyes);
}

void Pony::set_eyes(int _eyes)
{
	Pony::_eyes = _eyes;
}

int Pony::get_teeth() const
{
	return _teeth;
}

void Pony::set_teeth(int _teeth)
{
	Pony::_teeth = _teeth;
}

int Pony::get_tail() const
{
	return _tail;
}

void Pony::set_tail(int _tail)
{
	Pony::_tail = _tail;
}
