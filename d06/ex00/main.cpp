#include "print.hpp"
#include <sstream>

void	parse_float(std::string &str)
{
	str.resize(str.size() - 1);
	std::stringstream	s(str);
	float x;
	bool is_nanf = (str == "nanf" || str == "+inff" || str == "-inff");

	if (!(s >> x))
		exit(0);
	if (is_nanf)
		std::cout << "char: impossible" << std::endl
		<< "int: impossible" << std::endl;
	else
	{
		if (x > CHAR_MAX || x < CHAR_MIN)
			std::cout << "char: impossible" << std::endl;
		else
			printChar(static_cast<char>(x));
		if (x > INT_MAX || x < INT_MIN)
			std::cout << "int: impossible" << std::endl;
		else
			printInt(static_cast<int>(x));
	}
	printFloat(x, is_nanf);
	printDouble(static_cast<double>(x), is_nanf);
}

void	parse_double(std::string const &str)
{
	std::stringstream	converter(str);
	double				x;
	bool is_nanf = (str == "nan" || str == "+inf" || str == "-inf");


	if (!(converter >> x))
		exit(0);
	if (is_nanf)
		std::cout << "char: impossible" << std::endl
				  << "int: impossible" << std::endl;
	else
	{
		if (x > CHAR_MAX || x < CHAR_MIN)
			std::cout << "char: impossible" << std::endl;
		else
			printChar(static_cast<char>(x));
		if (x > INT_MAX || x < INT_MIN)
			std::cout << "int: impossible" << std::endl;
		else
			printInt(static_cast<int>(x));
	}
	if ((x > MAXFLOAT || x < std::numeric_limits<float>::min()) && !is_nanf)
		std::cout << "float: impossible" << std::endl;
	else
		printFloat(static_cast<float>(x), is_nanf);
	printDouble(x, is_nanf);
}

void	parse_int(std::string const &str)
{
	std::stringstream	x(str);
	int c;

	if (!(x >> c))
		exit(0);
	if (c < CHAR_MIN || c > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else
		printChar(static_cast<char>(c));
	printInt(c);
	printFloat(static_cast<float>(c), false);
	printDouble(static_cast<double>(c), false);
}

void	parse_char(std::string const &str)
{
	char c = str[0];

	printChar(c);
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c), false);
	printDouble(static_cast<double>(c), false);
}

void	print(std::string str)
{
	unsigned long		pos_first_f = str.find('f');
	unsigned long 		pos_dot = str.find('.');
	unsigned long		size = str.size();

	if (size > 1 && ((pos_dot != std::string::npos && pos_first_f != std::string::npos &&
		pos_first_f == size - 1 && isNumeric(str.substr(0, pos_dot)) && isNumeric(str.substr(pos_dot + 1, pos_first_f - pos_dot - 1)))
		|| str == "-inff" || str == "+inff" || str == "nanf"))
		parse_float(str);
	else if (size > 1 && ((pos_dot != std::string::npos && pos_first_f == std::string::npos && isNumeric(str.substr(0, pos_dot))
		&& isNumeric(str.substr(pos_dot + 1, size - pos_dot))) || str == "-inf" || str == "+inf" || str == "nan"))
		parse_double(str);
	else if (size == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		parse_char(str);
	else if (isNumeric(str))
		parse_int(str);
}

int main(int ac, char **av)
{
	if (ac == 2)
		print(av[1]);
}