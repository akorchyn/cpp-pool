#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <cstdlib>
#include <time.h>
#include <iostream>

Base *generate()
{
	signed char x = rand() % 3;

	if (x == 0)
	{
		std::cout << "Generated A" << std::endl;
		return static_cast<Base *>(new A);
	}
	std::cout << "Generated " << ((x == 1) ? "B" : "C") << std::endl;
	return x == 1 ? static_cast<Base *>(new B) : static_cast<Base *>(new C);
}

void identify_from_pointer(Base *secret)
{
	if (dynamic_cast<A *>(secret))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(secret))
		std::cout << "B" << std::endl;
	else
		std::cout << "C" << std::endl;
}

void identify_from_reference(Base &secret)
{
	try
	{
		A x = dynamic_cast<A &>(secret);
		std::cout << "A" << std::endl;
	}
	catch (std::exception &x)
	{
		try
		{
			B x = dynamic_cast<B &>(secret);
			std::cout << "B" << std::endl;
		}
		catch (std::exception &x)
		{
			std::cout << "C" << std::endl;
		}
	}
}

int main()
{
	srand(time(NULL));
	Base			*x = generate();

	identify_from_pointer(x);
	identify_from_reference(*x);
}
