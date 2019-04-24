#include "../includes/NetDisplay.hpp"

NetDisplay::NetDisplay()
{
}

NetDisplay::NetDisplay(__attribute__((unused))NetDisplay const &x)
{
}

NetDisplay &NetDisplay::operator=(__attribute__((unused))NetDisplay const &x)
{
	return *this;
}

NetDisplay::~NetDisplay()
{
}

void NetDisplay::drawCurses(WINDOW *winptr, int num)
{
	std::vector<std::string>	toParse;
	NetModule					info;
	int x, y;

	getmaxyx(winptr, y, x);
	info.getInfo(toParse);

	wattron(winptr, COLOR_PAIR(1));
	mvwprintw(winptr, y - 2, x / 2 - 1, "%d", num);
	mvwprintw(winptr, 1, x / 2 - 11, "NET throughput MODULE");
	wattron(winptr, COLOR_PAIR(2));
	mvwprintw(winptr, y / 2 - 1, x / 2 - 8, "Input  : %s", (toParse.at(0)).c_str());
	mvwprintw(winptr, y / 2 + 1, x / 2 - 8, "Output : %s", (toParse.at(1)).c_str());
	wattroff(winptr, COLOR_PAIR(2));
	box(winptr, 0, 0);
}
