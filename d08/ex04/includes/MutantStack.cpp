#include "MutantStack.hpp"

template<class T>
MutantStack<T>::MutantStack()
{
}

template<class T>
MutantStack<T>::MutantStack(MutantStack const &x)
{
	_stack = x._stack;
}

template<class T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &x)
{
	if (&x == this)
		return *this;
	_stack = x._stack;
	return *this;
}

template<class T>
MutantStack<T>::~MutantStack()
{
}

template<class T>
bool MutantStack<T>::empty()
{
	return _stack.size() == 0;
}

template<class T>
typename MutantStack<T>::size_type			MutantStack<T>::size()
{
	return _stack.size();
}

template<class T>
typename MutantStack<T>::reference MutantStack<T>::top()
{
	return _stack.back();
}

template<class T>
void MutantStack<T>::push(const_reference g)
{
	_stack.push_back(g);
}

template<class T>
void MutantStack<T>::pop()
{
	_stack.pop_back();
}

template<class T>
MutantStack<T>::operator std::stack<T>()
{
	std::stack<T>	n;

	for (reverse_iterator i = rbegin(); i != rend(); i++)
		n.push(*i);
	return n;
}

template<class T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return _stack.rbegin();
}

template<class T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin() const
{
	return _stack.crbegin();
}

template<class T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return _stack.rend();
}

template<class T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend() const
{
	return _stack.crend();
}

template<class T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return _stack.begin();
}

template<class T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin() const
{
	return _stack.cbegin();
}

template<class T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return _stack.end();
}

template<class T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend() const
{
	return _stack.cend();
}

template<class T>
std::ostream &operator<<(std::ostream &s, const MutantStack<T> &x)
{
	typename MutantStack<T>::const_iterator	it = x.cbegin();

	s << "ST";
	while (it != x.cend())
	{
		s << " " << *it;
		it++;
	}
	s << "]";
	return s;
}
