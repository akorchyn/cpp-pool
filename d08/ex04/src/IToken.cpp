#include "../includes/IToken.hpp"
#include <iomanip>

IToken::IToken()
{
}

IToken::IToken(int n, int priority) : _num(n), _priority(priority)
{
}

IToken::IToken(IToken const &x) : _num(x._num)
{
}


IToken &IToken::operator=(__attribute__((unused))IToken const &x)
{
	if (&x == this)
		return *this;
	_num = x._num;
	return *this;
}

IToken::~IToken()
{
}

std::ostream &operator<<(std::ostream &s, IToken *x)
{
	s << x->getString();
	return s;
}


int IToken::getPriority() const
{
	return _priority;
}
