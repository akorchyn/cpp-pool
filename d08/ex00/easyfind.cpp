#include <algorithm>

template <class T>
typename T::iterator	easyfind(T &x, int toFind)
{
	return std::find(x.begin(), x.end(), toFind);
}