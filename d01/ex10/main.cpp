#include <fstream>
#include <iostream>
#include <string>
#include <errno.h>

void	readFromConsole()
{
	for (char c = std::cin.get(); !std::cin.eof(); c = std::cin.get())
			std::cout << c;
}

void 	readFromFile(const std::string &filename)
{
	errno = 0;
	std::ifstream	file(filename);
	std::string		buff = "";

	if (!file.good())
	{
		std::cerr << "cat: " << filename << ": " << strerror(errno) << std::endl;
		return ;
	}
	for (char c = file.get(); !file.eof(); c = file.get())
		buff += c;
	std::cout << buff;
	file.close();
}

int main(int ac, char **av)
{
	if (ac == 1)
		readFromConsole();
	else
		for (int i = 1; i < ac; ++i)
			readFromFile(av[i]);
}