#include "B.hpp"

B::B()
{
}

B::B(B const &x)
{
	*this = x;
}

B &B::operator=(B const &x)
{
	static_cast<void>(x);
	return *this;
}

B::~B()
{
}
