#ifndef HELPER_ICE_HPP
#define HELPER_ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Ice : public AMateria
{
public:
	Ice();
	Ice(Ice const &x);
	Ice &operator=(Ice const &x);
	~Ice();

	virtual AMateria*	clone() const;
	virtual void		use(ICharacter& target);
};


#endif
