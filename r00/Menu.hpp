#ifndef RUSH00_MENU_HPP
#define RUSH00_MENU_HPP

#include <ncurses.h>
#include "Menu.hpp"

class Menu
{
public:
	Menu(int x, int y);
	~Menu();
	int		isStartGame();

private:
	Menu();
	Menu(Menu const &x);
	Menu &operator=(Menu const &x);
	void	_printStart(bool colored);
	void 	_printEnd(bool colored);

	WINDOW	*_win;
	int		mode;
};


#endif
