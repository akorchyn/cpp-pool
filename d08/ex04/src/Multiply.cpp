#include "Multiply.hpp"

Multiply::Multiply() : IToken('*', 3)
{
}

Multiply::Multiply(Multiply const &x) : IToken(x)
{
}

Multiply &Multiply::operator=(Multiply const &x)
{
	IToken::operator=(x);
	return *this;
}

Multiply::~Multiply()
{
}

std::string Multiply::getString() const
{
	return std::string("Op(") + static_cast<char>(_num) + ")";
}

void Multiply::execute(MutantStack<int> &x) const
{
	if (x.size() < 2)
		throw std::runtime_error("Operations are bad ordered");
	int n = x.top();
	x.pop();
	x.top() *= n;
	std::cout 	<< "I " << std::setw(10) << std::left << getString() << " | "
				 << std::setw(14) << std::left << "OP Multiply" << " | " << x << std::endl;
}
