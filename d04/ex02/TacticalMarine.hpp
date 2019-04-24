#ifndef HELPER_SPACEMARINE_HPP
#define HELPER_SPACEMARINE_HPP

#include "ISpaceMarine.hpp"
#include <iostream>

class TacticalMarine : public ISpaceMarine
{
public:
	TacticalMarine();
	~TacticalMarine();
	TacticalMarine(TacticalMarine const &x);
	TacticalMarine &operator=(TacticalMarine const &x);

	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
	ISpaceMarine *clone() const;
};


#endif
