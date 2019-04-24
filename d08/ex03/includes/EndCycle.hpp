#ifndef HELPER_ENDCYCLE_HPP
#define HELPER_ENDCYCLE_HPP

#include "StartCycle.hpp"
#include "IOperations.hpp"

class EndCycle : public IOperation
{
public:
	EndCycle();
	EndCycle(EndCycle const &x);
	EndCycle &operator=(EndCycle const &x);
	~EndCycle();

	void		execute(std::vector<char>::iterator &x, std::list<IOperation *>::iterator &queue) const;
	IOperation * clone();
};


#endif
