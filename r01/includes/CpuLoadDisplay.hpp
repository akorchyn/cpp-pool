#ifndef RUSH01_CPULOADDISPLAY_HPP
#define RUSH01_CPULOADDISPLAY_HPP

#include "IMonitorDisplay.hpp"
#include "CpuLoadModule.hpp"
#include <sstream>

class CpuLoadDisplay : public IMonitorDisplay
{
public:
	CpuLoadDisplay();
	CpuLoadDisplay(CpuLoadDisplay const &x);
	CpuLoadDisplay &operator=(CpuLoadDisplay const &x);
	~CpuLoadDisplay();

	void drawCurses(WINDOW *window, int num);

};


#endif
