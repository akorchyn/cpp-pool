#include "Span.hpp"

Span::Span()
{
}

Span::Span(unsigned n)
{
	_tab.reserve(n);
}

Span::Span(Span const &x) : _tab(x._tab)
{
}

void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	if ((_tab.capacity() - _tab.size()) < static_cast<unsigned long>(std::distance(start, end)))
		throw std::runtime_error("Not enough space left");
	_tab.assign(start, end);
}

Span &Span::operator=(Span const &x)
{
	if (&x == this)
		return *this;
	_tab = x._tab;
	return *this;
}

void Span::addNumber(int n)
{
	if (_tab.size() == _tab.capacity())
		throw std::runtime_error("Span already full");
	_tab.push_back(n);
}

int Span::shortestSpan()
{
	int 	b[2];

	if (_tab.empty() || _tab.size() == 1)
		throw std::runtime_error("there is no Span to find");
	std::partial_sort_copy(_tab.begin(), _tab.end(), b, b + 2);
	return b[1] - b[0];
}

int Span::longestSpan()
{
	if (_tab.empty() || _tab.size() == 1)
		throw std::runtime_error("there is no Span to find");
	return *std::max_element(_tab.begin(), _tab.end()) - *std::min_element(_tab.begin(), _tab.end());
}

Span::~Span()
{

}

