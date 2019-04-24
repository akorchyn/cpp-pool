#include "../includes/ParClose.hpp"

ParClose::ParClose() : IToken(')', 1)
{
}

ParClose::ParClose(ParClose const &x) : IToken(x)
{
}

ParClose &ParClose::operator=(ParClose const &x)
{
	IToken::operator=(x);
	return *this;
}

ParClose::~ParClose()
{
}

std::string ParClose::getString() const
{
	return "ParClose";
}

void ParClose::execute(__attribute__((unused))MutantStack<int> &x) const
{
}
