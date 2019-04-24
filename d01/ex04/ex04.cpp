#include <iostream>
#include <string>

int main()
{
	std::string		x = "HI THIS IS BRAIN";
	std::string		*x1 = &x;
	std::string		&x2 = x;

	std::cout << *x1 << std::endl;
	std::cout << x2 << std::endl;
}