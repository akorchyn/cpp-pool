#include "Span.hpp"
#include <iostream>
#include <vector>
int main()
{
	int tab[] = {5, 3, 17, 9, 11};
	std::vector<int> x;

	x.assign(tab, tab + 5);
	Span sp(5);

	sp.addNumber(x.begin(), x.end());
	Span sp1(10000);

	for (int i = 0; i < 10000; i++)
		sp1.addNumber(rand() % 500);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;
}