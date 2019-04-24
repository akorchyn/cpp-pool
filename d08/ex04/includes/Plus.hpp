#ifndef HELPER_PLUS_HPP
#define HELPER_PLUS_HPP

#include "IToken.hpp"

class Plus : public IToken
{
public:
	Plus();
	Plus(Plus const &x);
	Plus &operator=(Plus const &x);
	~Plus();

	std::string		getString() const;
	void execute(MutantStack<int> &x) const;
};


#endif
