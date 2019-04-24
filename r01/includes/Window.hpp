#ifndef RUSH01_WINDOW_HPP
#define RUSH01_WINDOW_HPP

#include <ncurses.h>
#include <vector>
#include "IMonitorDisplay.hpp"
#include "MonitorGenerator.hpp"

class Window
{
public:


	Window(bool isCurses);
	Window(Window const &x);
	Window &operator=(Window const &x);
	~Window();

	void	delMonitor(size_t index);
	void	setMonitor(IMonitorDisplay *);
	bool	update();
	void	handleButton();

private:
	Window();
	void 	_initCursesWins();
	void	refreshWins();
	void	clearWins();
	int 	_getIndex();
	void 	_drawMenu();
	void	_handleButtonCurses();
	void	delAll();

	std::vector<IMonitorDisplay *>	modules;
	std::vector<WINDOW *>			windows;
	WINDOW							*menu;
	bool	isCurses;
	bool	isClosed;
	int		maxY;
	int		maxX;
	size_t	maxModules;
};


#endif
