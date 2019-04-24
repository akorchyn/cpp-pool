#ifndef HELPER_PARCLOSE_HPP
#define HELPER_PARCLOSE_HPP

#include "IToken.hpp"

class ParClose : public IToken
{
public:
	ParClose();
	ParClose(ParClose const &x);
	ParClose &operator=(ParClose const &x);
	~ParClose();

	std::string getString() const;
	void execute(MutantStack<int> &x) const;
};


#endif
