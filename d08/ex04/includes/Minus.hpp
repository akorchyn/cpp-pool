#ifndef HELPER_MINUS_HPP
#define HELPER_MINUS_HPP

#include "IToken.hpp"

class Minus : public IToken
{
public:
	Minus();
	Minus(Minus const &x);
	Minus &operator=(Minus const &x);
	~Minus();

	std::string getString() const;
	void execute(MutantStack<int> &x) const;
};


#endif
