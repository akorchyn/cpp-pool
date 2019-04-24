#ifndef HELPER_SUPERMUTANT_HPP
#define HELPER_SUPERMUTANT_HPP

#include <iostream>
#include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
	SuperMutant();
	~SuperMutant();
	SuperMutant(SuperMutant const &x);
	SuperMutant &operator=(SuperMutant const &x);

	void takeDamage(int n);
};


#endif
