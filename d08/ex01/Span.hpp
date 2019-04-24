#ifndef HELPER_SPAN_HPP
#define HELPER_SPAN_HPP

#include <vector>

class Span
{
public:
	Span(unsigned n);
	Span(Span const &x);
	Span &operator=(Span const &x);
	void	addNumber(int n);
	void	addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
	int 	shortestSpan();
	int 	longestSpan();
	~Span();

private:
	Span();

	std::vector <int>	_tab;
};


#endif
