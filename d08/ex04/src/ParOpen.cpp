#include "../includes/ParOpen.hpp"

ParOpen::ParOpen() : IToken('(', 1)
{
}

ParOpen::ParOpen(ParOpen const &x) : IToken(x)
{
}

ParOpen &ParOpen::operator=(ParOpen const &x)
{
	IToken::operator=(x);
	return *this;
}

ParOpen::~ParOpen()
{
}

std::string ParOpen::getString() const
{
	return "ParOpen";
}

void ParOpen::execute(__attribute__((unused))MutantStack<int> &x) const
{
}
