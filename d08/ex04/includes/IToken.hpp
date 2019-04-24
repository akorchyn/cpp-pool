#ifndef HELPER_ITOKEN_HPP
#define HELPER_ITOKEN_HPP

#include <iostream>
#include <iomanip>
#include "MutantStack.cpp"

class IToken
{
public:
	IToken();
	IToken(int symb, int priority);
	IToken(IToken const &x);
	IToken &operator=(IToken const &x);
	virtual ~IToken();

	virtual std::string	getString() const = 0;
	virtual	void execute(MutantStack<int> &x) const = 0;
	int getPriority() const;

protected:
	int _num;
	int _priority;
};

std::ostream &operator<<(std::ostream &s, IToken *);

#endif
