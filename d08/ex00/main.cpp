#include "easyfind.cpp"
#include <vector>
#include <array>
#include <iostream>

int main()
{
	std::vector<int> x(10);
	std::array<int, 10> array;
	for (int i = 0; i < 10; i++)
	{
		x[i] = i;
		array[i] = i;
	}
	std::cout << std::boolalpha;
	std::cout << "To find 5 in vector. Returned object : " << *easyfind(x, 5) << std::endl;
	std::cout << "To find -5 in vector. Is returned object is x.end()? : " << (easyfind(x, -5) == x.end()) << std::endl;
	std::cout << "To find 5 in array. Returned object : " << *easyfind(array, 5) << std::endl;
	std::cout << "To find -5 in array. Is returned object is array.end()? : " << (easyfind(array, -5) == array.end()) << std::endl;

}