#ifndef HELPER_NUMBER_HPP
#define HELPER_NUMBER_HPP

#include "IToken.hpp"
#include <sstream>

class Number : public IToken
{
public:
	Number(int n);
	Number(Number const &x);
	Number &operator=(Number const &x);
	~Number();

	std::string	getString() const;
	void execute(MutantStack<int> &x) const;

private:
	Number();
};

#endif
