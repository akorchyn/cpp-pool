#ifndef RUSH01_DATEDISPLAY_HPP
#define RUSH01_DATEDISPLAY_HPP

#include "DateModule.hpp"
#include "IMonitorDisplay.hpp"

class DateDisplay : public IMonitorDisplay
{
public:
	DateDisplay();
	DateDisplay(DateDisplay const &x);
	DateDisplay &operator=(DateDisplay const &x);
	~DateDisplay();

	void drawCurses(WINDOW *window, int num);
};


#endif
