#include "../includes/RamLoadDisplay.hpp"

RamLoadDisplay::RamLoadDisplay()
{
}

RamLoadDisplay::RamLoadDisplay(__attribute__((unused))RamLoadDisplay const &x)
{
}

RamLoadDisplay &RamLoadDisplay::operator=(__attribute__((unused))RamLoadDisplay const &x)
{
	return *this;
}

RamLoadDisplay::~RamLoadDisplay()
{
}

void RamLoadDisplay::drawCurses(WINDOW *winptr, int num)
{
	std::vector<std::string>	toParse;
	RamLoadModule				info;
	std::stringstream			str;
	float 						percent;
	int x, y, count;

	box(winptr, 0, 0);
	getmaxyx(winptr, y, x);
	info.getInfo(toParse);
	str << toParse.at(0);
	str >> percent;
	count = (x - 2) * percent - 1;
	wattron(winptr, COLOR_PAIR(1));
	mvwprintw(winptr, y - 2, x / 2 - 1, "%d", num);
	mvwprintw(winptr, 1, x / 2 - 10, "Ram Available MODULE");
	wattron(winptr, COLOR_PAIR(2));
	mvwprintw(winptr, y / 2 - 1, x / 2 - 10, "%s%d%%", "Ram Available : ", static_cast<int>(percent * 100));
	wattron(winptr, COLOR_PAIR(3));
	for (int i = 0; i < count; i++)
	{
		mvwprintw(winptr, y / 2 + 1, i + 1, "%S", L"░░");
		mvwprintw(winptr, y / 2 + 2, i + 1, "%S", L"_/");
	}
	wattroff(winptr, COLOR_PAIR(3));
}