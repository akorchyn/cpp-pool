#include "../includes/MonitorGenerator.hpp"

MonitorGenerator::MonitorGenerator()
{
	func[HostnameUsername] = &MonitorGenerator::createHostnameUsernameMonitor;
	func[OS] = &MonitorGenerator::createOsMonitor;
	func[Date] = &MonitorGenerator::createTimeMonitor;
	func[CpuLoad] = &MonitorGenerator::createCpuLoadMonitor;
	func[RamAvailable] = &MonitorGenerator::createRamAvailableMonitor;
	func[Net] = &MonitorGenerator::createNetMonitor;
	func[Cat] = &MonitorGenerator::createCattyMonitor;
	func[Motivator] = &MonitorGenerator::createMotivatorMonitor;
}

MonitorGenerator::MonitorGenerator(MonitorGenerator const &x) : func(x.func)
{
}

MonitorGenerator &MonitorGenerator::operator=(MonitorGenerator const &x)
{
	if (&x == this)
		return *this;
	func = x.func;
	return *this;
}

MonitorGenerator::~MonitorGenerator()
{
}

IMonitorDisplay *MonitorGenerator::getDisplay(int x)
{
	if (func[x] == NULL)
		return NULL;
	return (this->*func[x])();
}

/*
 *  FUNC THAT RETURN DIFFERENT MONITORS
 */

IMonitorDisplay *MonitorGenerator::createHostnameUsernameMonitor()
{
	return new HostnameUsernameDisplay;
}

IMonitorDisplay *MonitorGenerator::createOsMonitor()
{
	return new OsDisplay;
}

IMonitorDisplay *MonitorGenerator::createTimeMonitor()
{
	return new DateDisplay;
}

IMonitorDisplay *MonitorGenerator::createCpuLoadMonitor()
{
	return new CpuLoadDisplay;
}

IMonitorDisplay *MonitorGenerator::createRamAvailableMonitor()
{
	return new RamLoadDisplay;
}

IMonitorDisplay *MonitorGenerator::createNetMonitor()
{
	return new NetDisplay;
}

IMonitorDisplay *MonitorGenerator::createCattyMonitor()
{
	return new CattyDisplay;
}

IMonitorDisplay *MonitorGenerator::createMotivatorMonitor()
{
	return new MotivatorDisplay;
}
