#ifndef POOL_B_HPP
#define POOL_B_HPP

#include "Base.hpp"

class B : public Base
{
public:
	B();
	B(B const &x);
	~B();
	B &operator=(B const &x);
};


#endif
