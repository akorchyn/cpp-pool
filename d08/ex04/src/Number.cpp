#include "../includes/Number.hpp"

Number::Number()
{
}

Number::Number(int n) : IToken(n, 4)
{
}

Number::Number(Number const &x) : IToken(x)
{
}

Number &Number::operator=(Number const &x)
{
	if (&x == this)
		return *this;
	IToken::operator=(x);
	return *this;
}

Number::~Number()
{
}

std::string Number::getString() const
{
	std::stringstream s;
	s << _num;

	return std::string("Num(") + s.str() + ")";
}

void Number::execute(MutantStack<int> &x) const
{
	x.push(_num);
	std::cout 	<< "I " << std::setw(10) << std::left << getString() << " | "
				 << std::setw(14) << std::left << "OP Push" << " | " << x << std::endl;
}
