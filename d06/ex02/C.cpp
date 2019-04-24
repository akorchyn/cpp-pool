#include "C.hpp"

C::C()
{
}

C::C(C const &x)
{
	*this = x;
}

C &C::operator=(C const &x)
{
	static_cast<void>(x);
	return *this;
}

C::~C()
{
}
