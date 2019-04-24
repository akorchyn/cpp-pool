#include <string>
#include "struct.hpp"
#include <cstdlib>
#include <time.h>
#include <iostream>

void	*serialize()
{
	const char alphanumeric[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *x = new char [16 + sizeof(int)];
	for (int i = 0; i < 8; i++)
		x[i] = alphanumeric[rand() % (sizeof(alphanumeric) - 1)];
	*reinterpret_cast<int *>(x + 8) = rand();
	for (int i = 12; i < 20; i++)
		x[i] = alphanumeric[rand() % (sizeof(alphanumeric) - 1)];
	return x;

}

Data *deserialize(void *raw)
{
	Data *x = new Data;

	x->s1 = std::string(reinterpret_cast<char *>(raw), 8);
	x->n = *(reinterpret_cast<int *>(raw) + 2);
	x->s2 = std::string(reinterpret_cast<char *>(raw) + 12, 8);
	return x;
}

int		main()
{
	srand(time(NULL));
	void *ser = serialize();
	Data *x = deserialize(ser);
	std::cout << x->s1 << std::endl;
	std::cout << x->n << std::endl;
	std::cout << x->s2 << std::endl;
	delete x;
	delete [] static_cast<char *>(ser);
}
