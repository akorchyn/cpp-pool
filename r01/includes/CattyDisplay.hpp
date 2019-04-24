#ifndef RUSH01_CATTYMONITOR_HPP
#define RUSH01_CATTYMONITOR_HPP

#include "IMonitorDisplay.hpp"

class CattyDisplay : public IMonitorDisplay
{
public:
	CattyDisplay();
	CattyDisplay(CattyDisplay const &x);
	CattyDisplay &operator=(CattyDisplay const &x);
	~CattyDisplay();

	void drawCurses(WINDOW *, int num);
};


#endif
