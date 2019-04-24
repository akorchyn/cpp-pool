#ifndef HELPER_SQUAD_HPP
#define HELPER_SQUAD_HPP

#include "ISquad.hpp"

#include <string>

class Squad : public ISquad
{
	int			_size;
	ISpaceMarine **_squad;

public:
	Squad();
	Squad(Squad const &x);
	Squad &operator=(Squad const &x);
	~Squad();


	int getCount() const;
	ISpaceMarine *getUnit(int) const;
	int			push(ISpaceMarine *x);

};


#endif
