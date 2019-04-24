#include <fstream>
#include <iostream>

void	get_value(std::string &filename, std::string &find, std::string &replace, int ac, char **av)
{
	if (ac == 4)
	{
		filename = av[1];
		find = av[2];
		replace = av[3];
	}
	else
	{
		std::cout << "Enter a file name : ";
		std::getline(std::cin, filename, '\n');
		std::cout << "Enter to find string : ";
		std::getline(std::cin, find, '\n');
		std::cout << "Enter replacing string : ";
		std::getline(std::cin, replace, '\n');
		std::ifstream input(filename);
		std::ofstream output(filename + ".replace");
	}
}

int main(int ac, char **av)
{
	std::string filename, find, replace, result;
	get_value(filename, find, replace, ac, av);
	std::ifstream input(filename);
	std::ofstream output(filename + ".replace");
	if (!input || !output)
	{
		std::cerr << "No such file" << std::endl;
		return (1);
	}
	while (!input.eof())
	{
		std::string tmp;
		std::getline(input, tmp, '\0');
		result += tmp;
	}
	input.close();
	size_t index;
	while ((index = result.find(find, 0)) != std::string::npos)
	{
		output.write(result.c_str(), index);
		output << replace;
		result = (result.c_str() + index + find.size());
	}
	output << result;
	output.close();
	return (0);
}
