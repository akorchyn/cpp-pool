#ifndef POOL_C_HPP
#define POOL_C_HPP

#include "Base.hpp"

class C : public Base
{
public:
	C();
	C(C const &x);
	~C();
	C &operator=(C const &x);
};


#endif
