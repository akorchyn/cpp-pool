#include "A.hpp"

A::A()
{
}

A::A(A const &x)
{
	*this = x;
}

A &A::operator=(A const &x)
{
	static_cast<void>(x);
	return *this;
}

A::~A()
{
}
