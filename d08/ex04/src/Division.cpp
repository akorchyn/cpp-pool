#include "Division.hpp"

Division::Division() : IToken('/', 3)
{

}

Division::Division(Division const &x) : IToken(x)
{
}

Division &Division::operator=(Division const &x)
{
	IToken::operator=(x);
	return *this;
}

Division::~Division()
{
}

std::string Division::getString() const
{
	return std::string("Op(") + static_cast<char>(_num) + ")";
}

void Division::execute(MutantStack<int> &x) const
{
	if (x.size() < 2)
		throw std::runtime_error("Operations are bad ordered");
	else if (x.top() == 0)
		throw std::runtime_error("Division by zero");
	int n = x.top();
	x.pop();
	x.top() /= n;
	std::cout 	<< "I " << std::setw(10) << std::left << getString() << " | "
				<< std::setw(14) << std::left << "OP Division" << " | " << x << std::endl;
}
