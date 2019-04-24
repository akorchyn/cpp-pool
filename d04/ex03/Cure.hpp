#ifndef HELPER_CURE_HPP
#define HELPER_CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(Cure const &x);
	Cure &operator=(Cure const &x);
	~Cure();

	virtual AMateria*	clone() const;
	virtual void		use(ICharacter& target);
};


#endif
