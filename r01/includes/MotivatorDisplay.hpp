#ifndef RUSH01_MOTIVATORDISPLAY_HPP
#define RUSH01_MOTIVATORDISPLAY_HPP

#include "IMonitorDisplay.hpp"
#include <string>

class MotivatorDisplay : public  IMonitorDisplay
{
public:
	MotivatorDisplay();
	MotivatorDisplay(MotivatorDisplay const &x);
	MotivatorDisplay &operator=(MotivatorDisplay const &x);
	~MotivatorDisplay();

	void drawCurses(WINDOW *winptr, int num);

};


#endif
