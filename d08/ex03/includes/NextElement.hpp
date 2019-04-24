#ifndef HELPER_NEXTELEMENT_HPP
#define HELPER_NEXTELEMENT_HPP

#include "IOperations.hpp"

class NextElement : public IOperation
{
public:
	NextElement();
	NextElement(NextElement const &x);
	NextElement &operator=(NextElement const &x);
	~NextElement();

	void 		execute(std::vector<char>::iterator &x, std::list<IOperation *>::iterator &queue) const;
	IOperation * clone();
};


#endif
