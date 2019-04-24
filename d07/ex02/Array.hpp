#ifndef HELPER_ARRAY_HPP
#define HELPER_ARRAY_HPP

#include <string>

template <class A>
class Array
{
public:
	Array();
	Array(size_t n);
	Array(Array const &x);
	Array<A> &operator=(Array<A> const &x);
	~Array();

	A		&operator[](size_t n);
	size_t 	size();

private:
	A		*_array;
	size_t	_size;
};

template<class A>
Array<A>::Array() : _array(NULL), _size(0)
{
}

template<class A>
Array<A>::Array(size_t n) : _array(new A [n]), _size(n)
{
}

template<class A>
Array<A>::Array(Array const &x) : _array(new A [x._size]), _size(x._size)
{
	for (int i = 0; i < _size; i++)
		_array[i] = x._array[i];
}

template<class A>
Array<A>	&Array<A>::operator=(Array const &x)
{
	if (&x == this)
		return *this;
	A	*tmp = new A [x._size];
	for (size_t i = 0; i < x._size; i++)
		tmp[i] = x._array[i];
	_size = x._size;
	delete [] _array;
	_array = tmp;
	return *this;
}

template<class A>
Array<A>::~Array()
{
	delete [] _array;
}

template<class A>
A &Array<A>::operator[](size_t n)
{
	if (n >= _size)
		throw std::runtime_error("Out of range");
	return _array[n];
}

template<class A>
size_t Array<A>::size()
{
	return _size;
}

#endif
