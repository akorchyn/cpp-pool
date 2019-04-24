#ifndef HELPER_RADSCORPION_HPP
#define HELPER_RADSCORPION_HPP

#include <iostream>
#include "Enemy.hpp"

class RadScorpion : public Enemy
{
public:
	RadScorpion();
	RadScorpion(RadScorpion const &x);
	RadScorpion &operator=(RadScorpion const &x);
	~RadScorpion();
};


#endif
