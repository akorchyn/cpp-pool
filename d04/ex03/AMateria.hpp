#ifndef HELPER_AMATERIA_HPP
#define HELPER_AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
private:
	unsigned int	_xp;
	std::string		_type;

public:
	AMateria(std::string const &x);
	AMateria(AMateria const &x);
	AMateria &operator=(AMateria const &x);
	virtual ~AMateria();

	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

	std::string	const	&getType();
	unsigned int		getXP();
};


#endif
