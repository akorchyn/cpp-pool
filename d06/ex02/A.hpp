#ifndef POOL_A_HPP
#define POOL_A_HPP

#include "Base.hpp"

class A : public  Base
{
public:
	A();
	A(A const &x);
	~A();
	A &operator=(A const &x);
};


#endif
