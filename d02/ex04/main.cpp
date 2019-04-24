#include "evalExpr.hpp"

void	error(std::string error)
{
	std::cerr << error << std::endl;
	exit (0);
}

void	operation(Fixed *nums, int &numCounter, char c)
{
	if (c == ' ')
		return ;
	else if (c == '#')
		nums[numCounter - 1] = nums[numCounter - 1] * Fixed(-1);
	else if (numCounter == 0 || numCounter == 1)
		error("Bad expression");
	else if (c == '+')
	{
		nums[numCounter - 2] = nums[numCounter - 2] + nums[numCounter - 1];
		numCounter--;
	}
	else if (c == '-')
	{
		nums[numCounter - 2] = nums[numCounter - 2] - nums[numCounter - 1];
		numCounter--;
	}
	else if (c == '*')
	{
		nums[numCounter - 2] = nums[numCounter - 2] * nums[numCounter - 1];
		numCounter--;
	}
	else if (c == '/')
	{
		if (nums[numCounter - 1].getRawBits() == 0)
		{
			error("Division by zero");
		}
		nums[numCounter - 2] = nums[numCounter - 2] / nums[numCounter - 1];
		numCounter--;
	}
	else
		error("Bad expression");
}

void	printAnswer(const std::string &polishNotation)
{
	std::istringstream  x(polishNotation);
	std::string			str;
	Fixed				nums[128] = {};
	int 				numCounter = 0;

	while (std::getline(x, str, ' ') || std::getline(x, str, '\0'))
	{
		float	tmp;

		if (isdigit(str[0]))
		{
			std::stringstream convertToFloat(str);
			convertToFloat >> tmp;
			nums[numCounter++] = Fixed(tmp);
		}
		else
			operation(nums, numCounter, str[0]);
	}
	if (numCounter != 1)
	{
		std::cerr << "Bad expression" << std::endl;
		exit(0);
	}
	std::cout << "Result expression is : " << nums[0].toFloat() << std::endl;
}


int main(int ac, char **av)
{
	Fixed::verbose = false;
	if (ac != 2)
		std::cout << "To much arguments" << std::endl;
	std::string		polishNotation = parseToPolishNotation(av[1]);
	printAnswer(polishNotation);
}
