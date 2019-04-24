#ifndef HELPER_DIVISION_HPP
#define HELPER_DIVISION_HPP

#include "IToken.hpp"

class Division : public IToken
{
public:
	Division();
	Division(Division const &x);
	Division &operator=(Division const &x);
	~Division();

	std::string getString() const;
	void execute(MutantStack<int> &x) const;

};


#endif
