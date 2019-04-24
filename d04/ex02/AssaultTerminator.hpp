#ifndef HELPER_ASSAULTTERMINATOR_HPP
#define HELPER_ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"
#include <iostream>

class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator();
	AssaultTerminator(AssaultTerminator const &x);
	AssaultTerminator &operator=(const AssaultTerminator &x);
	~AssaultTerminator();

	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
	ISpaceMarine *clone() const;
};


#endif
