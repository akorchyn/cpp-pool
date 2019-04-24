#ifndef RUSH01_IMONITORDISPLAY_HPP
#define RUSH01_IMONITORDISPLAY_HPP

#include <ncurses.h>

class IMonitorDisplay
{
public:
	IMonitorDisplay();
	IMonitorDisplay(IMonitorDisplay const &x);
	IMonitorDisplay &operator=(IMonitorDisplay const &x);
	virtual ~IMonitorDisplay();

	virtual void drawCurses(WINDOW *, int num) = 0;
};


#endif
