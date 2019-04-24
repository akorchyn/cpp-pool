#ifndef HELPER_STARTCYCLE_HPP
#define HELPER_STARTCYCLE_HPP

#include "IOperations.hpp"
#include "EndCycle.hpp"

class StartCycle : public IOperation
{
public:
	StartCycle();
	StartCycle(StartCycle const &x);
	StartCycle &operator=(StartCycle const &x);
	~StartCycle();

	void		execute(std::vector<char>::iterator &x, std::list<IOperation *>::iterator &queue) const;
	IOperation * clone();
};


#endif
