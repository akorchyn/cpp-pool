#include "print.hpp"

void	printChar(char c)
{
	std::cout << "char: ";
	if (isprint(c))
		std::cout << '\'' << c << '\'' << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void	printInt(int c)
{
	std::cout << "int: " << c << std::endl;
}

void	printFloat(float c, bool is_nanf)
{
	float x;

	std::cout << "float: ";
	if (c == (5.0 / 0))
		std::cout << "+";
	std::cout << c;
	if (!std::modf(c, &x) && !is_nanf)
		std::cout << ".0";
	std::cout << "f\n";
}

void	printDouble(double c, bool is_nanf)
{
	double x;

	std::cout << "double: ";
	if (c == (5.0 / 0))
		std::cout << "+";
	std::cout << c;
	if (!std::modf(c, &x) && !is_nanf)
		std::cout << ".0";
	std::cout << std::endl;
}

bool	isNumeric(std::string const &x)
{
	unsigned long i = 0;

	if (x.size() == 0)
		return false;
	if (x[i] == '+' || x[i] == '-')
		i++;
	while (i < x.size())
	{
		if (!std::isdigit(x[i]))
			return false;
		i++;
	}
	return true;
}