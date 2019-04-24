#ifndef RUSH01_IMONITORMODULE_HPP
#define RUSH01_IMONITORMODULE_HPP

#include <vector>
#include <string>

class IMonitorModule
{
public:
	IMonitorModule();
	IMonitorModule(IMonitorModule const &x);
	IMonitorModule &operator=(IMonitorModule const &x);
	virtual ~IMonitorModule();

	virtual void getInfo(std::vector<std::string> &info) const = 0;
};


#endif
