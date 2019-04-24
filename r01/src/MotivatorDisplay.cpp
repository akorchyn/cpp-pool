#include "../includes/MotivatorDisplay.hpp"

MotivatorDisplay::MotivatorDisplay()
{
}

MotivatorDisplay::MotivatorDisplay(__attribute__((unused))MotivatorDisplay const &x)
{
}

MotivatorDisplay &MotivatorDisplay::operator=(__attribute__((unused))MotivatorDisplay const &x)
{
	return *this;
}

MotivatorDisplay::~MotivatorDisplay()
{
}

void MotivatorDisplay::drawCurses(WINDOW *winptr, int num)
{
	static int i = 0;
	std::string str[] = {"You are nice, yeey", "Really, I don't joke", "Have a nice day"};
	int x, y;
	int j = ++i / 500;


	if (i == 1499)
		i = 0;
	getmaxyx(winptr, y, x);
	wattron(winptr, COLOR_PAIR(1));
	mvwprintw(winptr, y - 2, x / 2 - 1, "%d", num);
	mvwprintw(winptr, 1, x / 2 - 9, "Motivation MODULE");
	wattron(winptr, COLOR_PAIR(2));
	mvwprintw(winptr, y / 2, x / 2 - str[j].size() / 2, "%s", str[j].c_str());
	wattroff(winptr, COLOR_PAIR(2));
	box(winptr, 0, 0);
}
