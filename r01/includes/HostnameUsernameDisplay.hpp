#ifndef RUSH01_HOSTNAMEUSERNAMEDISPLAY_HPP
#define RUSH01_HOSTNAMEUSERNAMEDISPLAY_HPP

#include "IMonitorDisplay.hpp"
#include "HostnameUsernameModule.hpp"

class HostnameUsernameDisplay : public IMonitorDisplay
{
public:
	HostnameUsernameDisplay();
	HostnameUsernameDisplay(HostnameUsernameDisplay const &x);
	HostnameUsernameDisplay &operator=(HostnameUsernameDisplay const &x);
	~HostnameUsernameDisplay();

	void drawCurses(WINDOW *winptr, int num);
};


#endif
