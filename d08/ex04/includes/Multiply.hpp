#ifndef HELPER_MULTIPLY_HPP
#define HELPER_MULTIPLY_HPP

#include "IToken.hpp"

class Multiply : public IToken
{
public:
	Multiply();
	Multiply(Multiply const &x);
	Multiply &operator=(Multiply const &x);
	~Multiply();

	std::string getString() const;
	void execute(MutantStack<int> &x) const;
};


#endif
