#include "Pony.hpp"
#include <iostream>

void		ponyOnTheHeap()
{
	Pony	*x = new Pony;

	std::cout << "Pony on the heap:  " << x << std::endl;
	delete x;
}

void		ponyOnTheStack()
{
	Pony y;
	std::cout << "Pony on the stack: " << &y << std::endl;
}

int main()
{
	ponyOnTheHeap();
	ponyOnTheStack();
}

