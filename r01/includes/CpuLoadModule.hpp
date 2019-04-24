#ifndef RUSH01_CPULOADMONITOR_HPP
#define RUSH01_CPULOADMONITOR_HPP

#include "IMonitorModule.hpp"
#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>

class CpuLoadModule : public IMonitorModule
{
public:

	CpuLoadModule();
	CpuLoadModule(CpuLoadModule const &x);
	CpuLoadModule &operator=(CpuLoadModule const &x);
	~CpuLoadModule();

	void getInfo(std::vector<std::string> &info) const;

};


#endif
