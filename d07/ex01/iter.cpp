#include <iostream>

template<class A, class B>
void 	iter(A *array, B length, void (*func)(A &))
{
	for (B i = 0; i < length; i++)
		func(array[i]);
}

template <class A>
void	print(A c)
{
	std::cout << c;
}

int main()
{
	const char gavno[] = "abcde";
	const int  tab[] = {5, 4, 3, 2, 1, 0};

	iter(gavno, sizeof(gavno) - 1, print);
	iter(tab, sizeof(tab) / 4, print);

}
