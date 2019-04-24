#ifndef HELPER_PREVELEMENT_HPP
#define HELPER_PREVELEMENT_HPP

#include "IOperations.hpp"

class PrevElement : public IOperation
{
public:
	PrevElement();
	PrevElement(PrevElement const &x);
	PrevElement &operator=(PrevElement const &x);
	~PrevElement();

	void		execute(std::vector<char>::iterator &x, std::list<IOperation *>::iterator &queue) const;
	IOperation * clone();

};


#endif
