#ifndef HELPER_IGNORE_HPP
#define HELPER_IGNORE_HPP

#include "IOperations.hpp"

class Ignore : public IOperation
{
public:
	Ignore();
	Ignore(Ignore const &x);
	Ignore &operator=(Ignore const &x);
	~Ignore();

	void		execute(std::vector<char>::iterator &x,
						std::list<IOperation *>::iterator &queue) const;
	IOperation * clone();
};


#endif
