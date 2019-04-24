#ifndef HELPER_PAROPEN_HPP
#define HELPER_PAROPEN_HPP

#include "IToken.hpp"

class ParOpen : public  IToken
{
public:
	ParOpen();
	ParOpen(ParOpen const &x);
	ParOpen &operator=(ParOpen const &x);
	~ParOpen();

	std::string getString() const;
	void execute(MutantStack<int> &x) const;
};


#endif
