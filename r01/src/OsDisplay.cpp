#include "../includes/OsDisplay.hpp"
#include "../includes/OsModule.hpp"

OsDisplay::OsDisplay()
{
}

OsDisplay::OsDisplay(__attribute__((unused))OsDisplay const &x)
{
}

OsDisplay &OsDisplay::operator=(__attribute__((unused))OsDisplay const &x)
{
	return *this;
}

OsDisplay::~OsDisplay()
{
}

void OsDisplay::drawCurses(WINDOW *winptr, int num)
{
	std::vector<std::string>	toParse;
	OsModule					info;
	int x, y;

	box(winptr, 0, 0);
	getmaxyx(winptr, y, x);
	info.getInfo(toParse);




	wattron(winptr, COLOR_PAIR(1));
	mvwprintw(winptr, y - 2, x / 2 - 1, "%d", num);
	mvwprintw(winptr, 1, x / 2 - 12, "Operation System MODULE");
	wattron(winptr, COLOR_PAIR(2));
	mvwprintw(winptr, y / 2 - 1, x / 2 - (toParse.at(0)).size() / 2, "%s", (toParse.at(0)).c_str());
	mvwprintw(winptr, y / 2, x / 2 - (toParse.at(1)).size() / 2, "%s", (toParse.at(1)).c_str());
	mvwprintw(winptr, y / 2 + 1, x / 2 - (toParse.at(2)).size() / 2, "%s", (toParse.at(2)).c_str());
	wattroff(winptr, COLOR_PAIR(2));
}

