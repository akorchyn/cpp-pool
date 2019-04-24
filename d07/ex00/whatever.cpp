#include <iostream>

template <class T>
void	swap(T &one, T &second)
{
	T	tmp;

	tmp = one;
	one = second;
	second = tmp;
}

template <class T>
T	&min(T &one, T &second)
{
	return (one < second) ? one : second;
}

template <class T>
T	&max(T &one, T &second)
{
	return (one > second) ? one : second;
}

int main()
{
	{
		std::cout << "Ints section ____________" << std::endl;
		int x = 5;
		int y = 6;

		std::cout << x << "  " << y << "  min : " << min<int>(x, y) << std::endl;
		std::cout << x << "  " << y << "  max : " << max<const int>(x, y) << std::endl;
		std::cout << "Before swap : " << x << "  " << y << std::endl;
		std::swap(x, y);
		std::cout << "After : " << x << "  " << y << std::endl;
	}
	{
		std::cout << "float section _________" << std::endl;
		float x = 3.1;
		float y = 4.1;

		std::cout << x << "  " << y << "  min : " << min<float>(x, y) << std::endl;
		std::cout << x << "  " << y << "  max : " << max<const float>(x, y) << std::endl;
		std::cout << "Before swap : " << x << "  " << y << std::endl;
		std::swap(x, y);
		std::cout << "After : " << x << "  " << y << std::endl;
	}
	{
		std::cout << "char _________" << std::endl;
		char x = 'x';
		char y = 'f';

		std::cout << x << "  " << y << "  min : " << min<char>(x, y) << std::endl;
		std::cout << x << "  " << y << "  max : " << max<const char>(x, y) << std::endl;
		std::cout << "Before swap : " << x << "  " << y << std::endl;
		std::swap(x, y);
		std::cout << "After : " << x << "  " << y << std::endl;
	}

}
