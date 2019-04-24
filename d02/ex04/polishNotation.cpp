#include "evalExpr.hpp"

void			findStart(std::string &stack, std::string &res)
{
	int i = 0;

	for (i = stack.size() - 1; i >= 0 && stack[i] != '('; i--)
	{
		res += ' ';
		res += stack[i];
	}
	if (i == -1)
		i = 0;
	if (stack[i] != '(')
		error("Bad expression");
	stack.resize(i);
}

int 			getIndex(char c, char *arr)
{
	int i = 0;
	while (arr[i] != c)
		i++;
	return (i);
}

void			handleCommands(char c, std::string &stack, std::string &res)
{
	static char		commands[] = {'+', '-', '*', '/', '('};
	static int 		prioritate[] = {1, 1, 2, 2, 0};
	int				index = getIndex(c, commands);

	for (int size = stack.size(); size && prioritate[getIndex(stack[size - 1], commands)] >= prioritate[index]; size--)
	{
		res += ' ';
		res += stack[size - 1];
		stack.resize(size - 1);
	}
	stack += c;
}

void			parseChar(std::string &stack, std::string &res, char c)
{
	if (c == '(')
		stack += c;
	else if (c == ')')
		findStart(stack, res);
	else if (c == '+' || c == '-' || c == '/' || c == '*')
		handleCommands(c, stack, res);
	else
		error(std::string("Error on character : ") + c);
}

void			parseNum(size_t &i, const std::string &str, std::string &res)
{
	if (res.size())
		res += ' ';
	while (isdigit(str[i]) || str[i] == '.')
		res += str[i++];
	i--;
}

std::string		collectResult(const std::string &result, const std::string &stack, const std::string &sign)
{
	std::string res = "";
	int 		count = 0;
	for (size_t i = 0; i < result.size(); i++)
	{
		res += result[i];
		if (isdigit(result[i]) && !isdigit(result[i + 1]) && sign[count++] == '-')
			res += " #";
	}
	for (int i = stack.size() - 1; i >= 0; i--)
		res = res + " " + stack[i];
	return (res);
}

std::string		parseToPolishNotation(const std::string &x)
{
	std::string		stack = "";
	std::string		result = "";
	std::string		sign = "";
	int 			isSign = 1;

	for (size_t i = 0; i < x.size(); i++)
	{
		if (x[i] == ' ')
			continue;
		else if (isSign && (x[i] == '-' || x[i] == '+') && isdigit(x[i + 1]))
		{
			sign += (x[i] == '-') ? '-' : '+';
			i++;
			isSign = 0;
			parseNum(i, x, result);
		}
		else if (isdigit(x[i]))
		{
			parseNum(i, x, result);
			sign += '+';
			isSign = 0;
		}
		else
		{
			x[i] != ')' && x[i] != '(' && (isSign = 1);
			parseChar(stack, result, x[i]);
		}
	}
	return collectResult(result, stack, sign);
}