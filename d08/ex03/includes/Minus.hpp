#ifndef HELPER_MINUS_HPP
#define HELPER_MINUS_HPP

#include "IOperations.hpp"

class Minus : public  IOperation
{
public:
	Minus();
	Minus(Minus const &x);
	Minus &operator=(Minus const &x);
	~Minus();

	virtual void	execute(std::vector<char>::iterator &x, std::list<IOperation *>::iterator &queue) const;
	IOperation * clone();
};


#endif
