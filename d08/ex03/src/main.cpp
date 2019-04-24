#include "../includes/Generator.hpp"
#include <iostream>
#include <vector>
#include <fstream>

void	deleteListContent(IOperation *x)
{
	delete x;
}

void	doOperations(std::list <IOperation *> &operations)
{
	std::vector <char>									x(30000, 0);
	std::vector <char>::iterator						memIt = x.begin();
	std::list <IOperation*>::iterator					queueIt = operations.begin();

	while (queueIt != operations.end())
	{
		(*queueIt)->execute(memIt, queueIt);
		queueIt++;
	}
	std::for_each(operations.begin(), operations.end(), &deleteListContent);
}

void	parse(std::ifstream &file)
{
	std::list <IOperation *>	operations;
	Generator					gen;
	char 						c;

	while (!file.eof() && (c = file.get()))
		operations.push_back(gen.getOperation(c));
	file.close();
	doOperations(operations);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./openmind [filename]" << std::endl;
		return 1;
	}
	std::ifstream	file(av[1]);
	if (!file.good())
	{
		std::cerr << "openmind: " << av[1] << ": " << strerror(errno) << std::endl;
		return 2;
	}
	parse(file);
}