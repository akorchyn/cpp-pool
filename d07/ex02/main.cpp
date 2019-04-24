#include "Array.hpp"
#include <iostream>

void memory()
{
	Array<int>		x;
	Array<int>		y(10);


	for (size_t i = 0; i < y.size(); i++)
		y[i] = i;
	x = y;
	for (size_t i = 0; i < x.size(); i++)
		std::cout << x[i] << std::endl;
	y = Array<int>();
	std::cout << "Size : " << y.size() << std::endl;
	try
	{
		x[40];
	}
	catch (std::exception &x)
	{
		std::cout << x.what() << std::endl;
	}

}

int main()
{
	memory();
	system("leaks array");
}