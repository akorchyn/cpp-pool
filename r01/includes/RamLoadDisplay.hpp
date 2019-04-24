#ifndef RUSH01_RAMLOADDISPLAY_HPP
#define RUSH01_RAMLOADDISPLAY_HPP

#include "RamLoadModule.hpp"
#include "IMonitorDisplay.hpp"
#include <sstream>

class RamLoadDisplay : public  IMonitorDisplay
{
public:
	RamLoadDisplay();
	RamLoadDisplay(RamLoadDisplay const &x);
	RamLoadDisplay &operator=(RamLoadDisplay const &x);
	~RamLoadDisplay();

	void drawCurses(WINDOW *window, int num);

};


#endif
