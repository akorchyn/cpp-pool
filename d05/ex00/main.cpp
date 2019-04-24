#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	x("loser", 150);

		x.decrement();
	}
	catch (std::exception &x)
	{
		std::cout << x.what() << std::endl;
	}

	try
	{
		Bureaucrat x("Super cool man", -5);

		std::cout << x.getName();
	}
	catch (std::exception &x)
	{
		std::cout << x.what() << std::endl;
	}

	try
	{
		Bureaucrat x("All ok", 50);

		x.decrement();
		x.increment();
		std::cout << x << std::endl;
	}
	catch (std::exception &x)
	{
		std::cout << x.what();
	}

}