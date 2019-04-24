#include "Menu.hpp"

Menu::Menu()
{}

Menu::Menu(Menu const &x)
{
	static_cast<void>(x);
}

Menu &Menu::operator=(Menu const &x)
{
	static_cast<void>(x);
	return *this;
}

void Menu::_printStart(bool colored)
{
	if (colored)
		wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 5, 5, "%s", " #####  #######    #    ######  #######");
	mvwprintw(_win, 6, 5, "%s", "#     #    #      # #   #     #    #");
	mvwprintw(_win, 7, 5, "%s", "#          #     #   #  #     #    #");
	mvwprintw(_win, 8, 5, "%s", " #####     #    #     # ######     #");
	mvwprintw(_win, 9, 5, "%s", "      #    #    ####### #   #      #");
	mvwprintw(_win, 10, 5, "%s", "#     #    #    #     # #    #     #");
	mvwprintw(_win, 11, 5, "%s", " #####     #    #     # #     #    #");
	if (colored)
		wattroff(_win, COLOR_PAIR(1));
}

void Menu::_printEnd(bool colored)
{
	if (colored)
		wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, 15, 15, "%s", "###### #    # # #####");
	mvwprintw(_win, 16, 15, "%s", "#       #  #  #   #");
	mvwprintw(_win, 17, 15, "%s", "#####    ##   #   #");
	mvwprintw(_win, 18, 15, "%s", "#        ##   #   #");
	mvwprintw(_win, 19, 15, "%s", "#       #  #  #   #");
	mvwprintw(_win, 20, 15, "%s", "###### #    # #   #");
	if (colored)
		wattroff(_win, COLOR_PAIR(1));
}

int		Menu::isStartGame()
{
	while (true)
	{
		box(_win, 0, 0);
		_printStart(mode == 1);
		_printEnd(mode == 2);
		int c = getch();
		if (c == KEY_UP || c == KEY_DOWN)
			mode = (mode == 1) ? 2 : 1;
		else if (c == 10)
			break ;
		wrefresh(_win);
	}
	wclear(_win);
	wrefresh(_win);
	return mode == 1;
}

Menu::Menu(int cols, int rows) : mode(1)
{
	_win = newwin(26, 50, rows / 2 - 13, cols / 2 - 25);
	wrefresh(_win);
}

Menu::~Menu()
{
	delwin(_win);
}
