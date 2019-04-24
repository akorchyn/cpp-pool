#ifndef IOPERATIONS_HPP
#define IOPERATIONS_HPP

#include <vector>
#include <list>

class IOperation
{
public:
	IOperation();
	IOperation(IOperation const &x);
	IOperation &operator=(IOperation const &x);
	virtual								~IOperation() {};
	virtual void						execute(std::vector<char>::iterator &x, std::list<IOperation *>::iterator &queue) const = 0;
	virtual IOperation * clone() = 0;
};

#endif
