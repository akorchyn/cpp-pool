#ifndef RUSH01_NETDISPLAY_HPP
#define RUSH01_NETDISPLAY_HPP

#include "IMonitorDisplay.hpp"
#include "NetModule.hpp"

class NetDisplay : public IMonitorDisplay
{
public:
	NetDisplay();
	NetDisplay(NetDisplay const &x);
	NetDisplay &operator=(NetDisplay const &x);
	~NetDisplay();

	void	drawCurses(WINDOW *win, int num);
};


#endif
