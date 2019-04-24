#include "../includes/HostnameUsernameDisplay.hpp"

HostnameUsernameDisplay::HostnameUsernameDisplay()
{
}

HostnameUsernameDisplay::HostnameUsernameDisplay(__attribute__((unused))HostnameUsernameDisplay const &x)
{
}

HostnameUsernameDisplay &HostnameUsernameDisplay::operator=(__attribute__((unused))HostnameUsernameDisplay const &x)
{
	return *this;
}

HostnameUsernameDisplay::~HostnameUsernameDisplay()
{
}

void HostnameUsernameDisplay::drawCurses(WINDOW *winptr, int num)
{
	std::vector<std::string>	toParse;
	HostnameUsernameModule		info;
	int x, y;

	box(winptr, 0, 0);
	getmaxyx(winptr, y, x);
	info.getInfo(toParse);



	wattron(winptr, COLOR_PAIR(1));
	mvwprintw(winptr, y - 2, x / 2 - 1, "%d", num);
	mvwprintw(winptr, 1, x / 2 - 10, "Host and User MODULE");
	wattron(winptr, COLOR_PAIR(2));
	mvwprintw(winptr, y / 2 - 1, x / 2 - (toParse.at(0)).size() / 2, "%s", (toParse.at(0)).c_str());
	mvwprintw(winptr, y / 2 + 1, x / 2 - (toParse.at(1)).size() / 2, "%s", (toParse.at(1)).c_str());
	wattroff(winptr, COLOR_PAIR(2));
}
