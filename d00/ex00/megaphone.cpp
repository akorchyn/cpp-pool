#include <iostream>
#include <cstring>
#include <locale>

int main(int ac, char **av)
{
	std::locale loc;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	for (int i = 1; i < ac; i++)
	{
		int _size = strlen(av[i]);
		for (int j = 0; j < _size; j++)
			std::cout << std::toupper(av[i][j], loc);
	}
	std::cout << std::endl;
}