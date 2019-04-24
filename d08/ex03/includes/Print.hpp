#ifndef HELPER_PRINT_HPP
#define HELPER_PRINT_HPP

#include "IOperations.hpp"
#include <iostream>

class Print : public  IOperation
{
public:
	Print();
	Print(Print const &x);
	Print &operator=(Print const &x);
	~Print();

	void 		execute(std::vector<char>::iterator &x, std::list<IOperation *>::iterator &queue) const;
	IOperation * clone();
};


#endif
