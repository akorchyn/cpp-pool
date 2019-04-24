#include "../includes/CpuLoadModule.hpp"

unsigned long long _previousTotalTicks = 0;
unsigned long long _previousIdleTicks = 0;

CpuLoadModule::CpuLoadModule()
{
}

CpuLoadModule::CpuLoadModule(__attribute__((unused))CpuLoadModule const &x)
{
}

CpuLoadModule &CpuLoadModule::operator=(__attribute__((unused))CpuLoadModule const &x)
{
	return *this;
}

CpuLoadModule::~CpuLoadModule()
{
}

float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
	unsigned long long totalTicksSinceLastTime = totalTicks - _previousTotalTicks;
	unsigned long long idleTicksSinceLastTime  = idleTicks - _previousIdleTicks;
	float ret = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);
	_previousTotalTicks = totalTicks;
	_previousIdleTicks  = idleTicks;
	return ret;
}

float GetCPULoad()
{
	host_cpu_load_info_data_t cpuinfo;
	mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
	if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
	{
		unsigned long long totalTicks = 0;
		for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
		return CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
	}
	else return -1.0f;
}

void CpuLoadModule::getInfo(std::vector<std::string> &info) const
{
	static float tmp = GetCPULoad();
	static clock_t t = clock();
	int 	x = clock() - t;

	if (x > 50000)
	{
		tmp = GetCPULoad();
		t = clock();
	}
	info.push_back(std::to_string(tmp));
}