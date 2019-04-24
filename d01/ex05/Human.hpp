#ifndef HELPER_HUMAN_HPP
#define HELPER_HUMAN_HPP

#include "Brain.hpp"
#include <sstream>

class Human
{
	const Brain	x;
public:
	std::string	identify();
	const Brain &getBrain() const;
};


#endif
