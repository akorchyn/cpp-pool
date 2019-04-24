#include "../includes/Plus.hpp"

Plus::Plus() : IToken('+', 2)
{

}

Plus::Plus(Plus const &x) : IToken(x)
{
}

Plus &Plus::operator=(Plus const &x)
{
	IToken::operator=(x);
	return *this;
}

Plus::~Plus()
{
}

std::string Plus::getString() const
{
	return std::string("Op(") + static_cast<char>(_num) + ")";
}

void Plus::execute(MutantStack<int> &x) const
{
	if (x.size() < 2)
		throw std::runtime_error("Operations are bad ordered");
	int n = x.top();
	x.pop();
	x.top() += n;
	std::cout 	<< "I " << std::setw(10) << std::left << getString() << " | "
				 << std::setw(14) << std::left << "OP Add" << " | " << x << std::endl;
}
