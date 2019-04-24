#ifndef HELPER_PLUS_HPP
#define HELPER_PLUS_HPP

#include "IOperations.hpp"

class Plus : public IOperation
{
public:
	Plus();
	Plus(Plus const &x);
	Plus &operator=(Plus const &x);
	~Plus();

	void 		execute(std::vector<char>::iterator &x, std::list<IOperation *>::iterator &queue) const;
	IOperation * clone();

};


#endif
