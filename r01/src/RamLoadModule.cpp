#include "../includes/RamLoadModule.hpp"

RamLoadModule::RamLoadModule()
{
}

RamLoadModule::RamLoadModule(__attribute__((unused))RamLoadModule const &x)
{
}

RamLoadModule &RamLoadModule::operator=(__attribute__((unused))RamLoadModule const &x)
{
	return *this;
}

RamLoadModule::~RamLoadModule()
{
}

static double ParseMemValue(const char * b)
{
	while((*b)&&(std::isdigit(*b) == false)) b++;
	return std::isdigit(*b) ? std::atof(b) : -1.0;
}


float GetSystemMemoryUsagePercentage()
{
	FILE * fpIn = popen("/usr/bin/vm_stat", "r");
	if (fpIn)
	{
		double pagesUsed = 0.0, totalPages = 0.0;
		char buf[512];
		while(fgets(buf, sizeof(buf), fpIn) != NULL)
		{
			if (strncmp(buf, "Pages", 5) == 0)
			{
				double val = ParseMemValue(buf);
				if (val >= 0.0)
				{
					if ((strncmp(buf, "Pages wired", 11) == 0)||(strncmp(buf, "Pages active", 12) == 0)) pagesUsed += val;
					totalPages += val;
				}
			}
			else if (strncmp(buf, "Mach Virtual Memory Statistics", 30) != 0) break;  // Stop at "Translation Faults", we don't care about anything at or below that
		}
		pclose(fpIn);

		if (totalPages > 0.0) return (float) (pagesUsed/totalPages);
	}
	return -1.0f;
}

void RamLoadModule::getInfo(std::vector<std::string> &info) const
{
	info.push_back(std::to_string(GetSystemMemoryUsagePercentage()));
}