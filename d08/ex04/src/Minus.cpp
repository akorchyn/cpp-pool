#include "Minus.hpp"

Minus::Minus() : IToken('-', 2)
{
}

Minus::Minus(Minus const &x) : IToken(x)
{
}

Minus &Minus::operator=(Minus const &x)
{
	IToken::operator=(x);
	return *this;
}

Minus::~Minus()
{
}

std::string Minus::getString() const
{
	return std::string("Op(") + static_cast<char>(_num) + ")";
}

void Minus::execute(MutantStack<int> &x) const
{
	if (x.size() < 2)
		throw std::runtime_error("Operations are bad ordered");
	int n = x.top();
	x.pop();
	x.top() -= n;
	std::cout 	<< "I " << std::setw(10) << std::left << getString() << " | "
				 << std::setw(14) << std::left << "OP Substract" << " | " << x << std::endl;
}
