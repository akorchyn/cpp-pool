#ifndef RUSH01_MONITORGENERATOR_HPP
#define RUSH01_MONITORGENERATOR_HPP

#include <map>
#include "IMonitorDisplay.hpp"
#include "HostnameUsernameDisplay.hpp"
#include "CpuLoadDisplay.hpp"
#include "OsDisplay.hpp"
#include "DateDisplay.hpp"
#include "RamLoadDisplay.hpp"
#include "NetDisplay.hpp"
#include "CattyDisplay.hpp"
#include "MotivatorDisplay.hpp"
#include <errno.h>

enum Monitors
{
	HostnameUsername,
	OS,
	Date,
	CpuLoad,
	RamAvailable,
	Net,
	Cat,
	Motivator
};

class MonitorGenerator
{
public:
	MonitorGenerator();
	MonitorGenerator(MonitorGenerator const &x);
	MonitorGenerator &operator=(MonitorGenerator const &x);
	~MonitorGenerator();

	IMonitorDisplay	*getDisplay(int x);

private:
	std::map <int, IMonitorDisplay *(MonitorGenerator::*)()>	func;
	IMonitorDisplay *createHostnameUsernameMonitor();
	IMonitorDisplay *createOsMonitor();
	IMonitorDisplay *createTimeMonitor();
	IMonitorDisplay *createCpuLoadMonitor();
	IMonitorDisplay *createRamAvailableMonitor();
	IMonitorDisplay *createNetMonitor();
	IMonitorDisplay *createCattyMonitor();
	IMonitorDisplay *createMotivatorMonitor();
};


#endif
