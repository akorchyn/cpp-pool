#ifndef HELPER_INPUT_HPP
#define HELPER_INPUT_HPP

#include "IOperations.hpp"
#include <iostream>

class Input : public IOperation
{
public:
	Input();
	Input(Input const &x);
	Input &operator=(Input const &x);
	~Input();

	void execute(std::vector<char>::iterator &x, std::list<IOperation *>::iterator &queue) const;
	IOperation *clone();
};


#endif
