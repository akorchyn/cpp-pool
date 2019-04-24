#ifndef RUSH01_OSDISPLAY_HPP
#define RUSH01_OSDISPLAY_HPP

#include "IMonitorDisplay.hpp"

class OsDisplay : public IMonitorDisplay
{
public:
	OsDisplay();
	OsDisplay(OsDisplay const &x);
	OsDisplay &operator=(OsDisplay const &x);
	~OsDisplay();

	void drawCurses(WINDOW *winptr, int num);

};


#endif
