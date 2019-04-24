#include "../includes/CattyDisplay.hpp"

CattyDisplay::CattyDisplay()
{
}

CattyDisplay::CattyDisplay(__attribute__((unused))CattyDisplay const &x)
{
}

CattyDisplay &CattyDisplay::operator=(__attribute__((unused))CattyDisplay const &x)
{
	return *this;
}

CattyDisplay::~CattyDisplay()
{
}

void CattyDisplay::drawCurses(WINDOW *winptr, int num)
{
	int x, y;

	const char *catty[] = {"     |\\      _,,,---,,_",
					   "     /,`.-'`'    -.  ;-;;,_",
					   "    |,4-  ) )-,_. ,\\ (  `'-'",
					   "   '---''(_/--'  `-'\\_)"};

	getmaxyx(winptr, y, x);

	wattron(winptr, COLOR_PAIR(1));
	mvwprintw(winptr, y - 2, x / 2 - 1, "%d", num);
	mvwprintw(winptr, 1, x / 2 - 10, "Sweaty Catty MODULE");
	wattron(winptr, COLOR_PAIR(2));
	for (int i = 0, startLineY = y / 2 - 2, startLineX = x / 2 - 15; i < 4; i++, startLineY++)
		mvwprintw(winptr, startLineY, startLineX, "%s", catty[i]);
	wattroff(winptr, COLOR_PAIR(2));
	box(winptr, 0, 0);
}
