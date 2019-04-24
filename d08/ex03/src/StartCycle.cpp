#include "../includes/StartCycle.hpp"

StartCycle::StartCycle()
{
}

StartCycle::StartCycle(StartCycle const &x)
{
	*this = x;
}

StartCycle &StartCycle::operator=(StartCycle const __attribute__((unused))&x)
{
	return *this;
}

StartCycle::~StartCycle()
{
}

void StartCycle::execute(std::vector<char>::iterator &x,
						 std::list<IOperation *>::iterator &queue) const
{
	int brackets = 1;

	if (!*x)
	{
		queue++;
		while (brackets != 0)
		{
			if (dynamic_cast<StartCycle *>(*queue))
				brackets++;
			else if (dynamic_cast<EndCycle *>(*queue))
				brackets--;
			queue++;
		}
	}
}

IOperation * StartCycle::clone()
{
	return (new StartCycle);
}
