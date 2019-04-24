#ifndef RUSH01_RAMLOADMODULE_HPP
#define RUSH01_RAMLOADMODULE_HPP

#include "IMonitorModule.hpp"

class RamLoadModule : public IMonitorModule
{
public:
	RamLoadModule();
	RamLoadModule(RamLoadModule const &x);
	RamLoadModule &operator=(RamLoadModule const &x);
	~RamLoadModule();

	void	getInfo(std::vector<std::string> &info) const;
};


#endif
