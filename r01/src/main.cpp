#include "../includes/Window.hpp"

void	loop()
{
	Window	x(true);

	while (x.update())
	{
		x.handleButton();
		usleep(10000);
	}
}

int main()
{
	setlocale(LC_ALL, "");

	loop();
}