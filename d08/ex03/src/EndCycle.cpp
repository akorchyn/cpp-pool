#include <memory>
#include "EndCycle.hpp"

EndCycle::EndCycle()
{
}

EndCycle::EndCycle(EndCycle const &x)
{
	*this = x;
}

EndCycle &EndCycle::operator=(EndCycle const __attribute__((unused))&x)
{
	return *this;
}

EndCycle::~EndCycle()
{
}

void EndCycle::execute(std::vector<char>::iterator &x,
					   std::list<IOperation *>::iterator &queue) const
{
	int i = 1;

	if (*x)
	{
		queue--;
		while (i != 0)
		{
			if (dynamic_cast<EndCycle *>(*queue))
				i++;
			else if (dynamic_cast<StartCycle *>(*queue))
				i--;
			queue--;
		}
	}
}

IOperation * EndCycle::clone()
{
	return new EndCycle;
}
