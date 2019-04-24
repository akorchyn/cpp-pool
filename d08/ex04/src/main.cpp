#include "../includes/TokenGenerator.hpp"
#include <list>
#include <stack>
#include <iostream>
#include <errno.h>

void	printList(std::string const &x, std::list <IToken *> const &lst)
{
	std::list<IToken *>::const_iterator	listIt = lst.cbegin();

	std::cout << x;
	while (listIt != lst.cend())
	{
		std::cout << " " << *listIt;
		listIt++;
	}
	std::cout << std::endl;
}

void	parse(std::string const &expression, std::list <IToken *> &normalNotation)
{
	std::string::const_iterator	exprIt = expression.cbegin();
	TokenGenerator				gen;


	while (exprIt != expression.cend())
	{
		if (*exprIt == ' ')
			exprIt++;
		else
		{
			try
			{
				normalNotation.push_back(gen.generatateToken(exprIt));
			}
			catch (std::exception &x)
			{
				std::cerr << x.what() << std::endl;
				exit(1);
			}
		}
	}
}

void closeBrackets(std::list<IToken *> &polish, MutantStack<IToken *> &stack)
{
	int i = 0;

	if (stack.empty())
		throw std::runtime_error("Bad parentess");
	while (stack.top()->getPriority() != 1)
	{
		i++;
		polish.push_back(stack.top());
		stack.pop();
		if (stack.empty())
			throw std::runtime_error("Bad parentess");
	}
	if (i == 0)
		throw std::runtime_error("Parantess contain nothing");
	stack.pop();
}

void	parseToPolishNotation(std::list <IToken *> const &normal, std::list <IToken *> &polish)
{
	std::list <IToken *>::const_iterator	x = normal.cbegin();
	MutantStack <IToken *>					tmpStack;
	int 									parentess = 0;

	while (x != normal.cend())
	{
		if ((*x)->getPriority() == 4)
			polish.push_back(*x);
		else if ((*x)->getPriority() == 1 && dynamic_cast<ParClose *>(*x))
		{
			parentess--;
			closeBrackets(polish, tmpStack);
		}
		else if (tmpStack.size() == 0 || (*x)->getPriority() == 1)
		{
			((*x)->getPriority() == 1) ? ++parentess : 0;
			tmpStack.push(*x);
		}
		else
		{
			while (tmpStack.size() && tmpStack.top()->getPriority() >= (*x)->getPriority())
			{
				polish.push_back(tmpStack.top());
				tmpStack.pop();
			}
			tmpStack.push(*x);
		}
		x++;
	}
	polish.insert(polish.end(), tmpStack.begin(), tmpStack.end());
	if (parentess != 0)
		throw std::runtime_error("Open and close brackets aren't equal");
}

void printResult(std::list <IToken *> &polishNotation)
{
	MutantStack<int>					stack;
	std::list <IToken *>::iterator it = polishNotation.begin();

	while (it != polishNotation.end())
	{
		try
		{
			(*it)->execute(stack);
		}
		catch (std::exception &x)
		{
			std::cerr	<< "Expression is not valid. Error: " << x.what() << std::endl
						<< "On: " << *it << std::endl;
			exit(0);
		}
		it++;
	}
	if (stack.size() != 1)
		std::cerr << "Expression not valid. Stack is not one element. Check yours OP" << std::endl;
	else
		std::cout << "Result : " << stack.top() << std::endl;
}

void	deleteListContent(IToken *x)
{
	delete x;
}

int main(int ac, char **av)
{
	std::list <IToken *>	normal;
	std::list <IToken *>	polishNotation;
	if (ac != 2)
	{
		std::cerr << "Usage: ./notation [expression]" << std::endl;
		return 0;
	}
	try
	{
		parse(av[1], normal);
		parseToPolishNotation(normal, polishNotation);
	}
	catch (std::exception &x)
	{
		std::cerr << "Expression is not valid. ERROR: " << x.what() << std::endl;
		return 2;
	}
	if (normal.empty())
	{
		std::cerr << "Empty string" << std::endl;
		return 3;
	}
	printList("Tokens:", normal);
	printList("Postfix :", polishNotation);
	printResult(polishNotation);
	std::for_each(polishNotation.begin(), polishNotation.end(), deleteListContent);
}