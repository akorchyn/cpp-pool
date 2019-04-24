#ifndef RUSH01_NETMODULE_HPP
#define RUSH01_NETMODULE_HPP

#include "IMonitorModule.hpp"
#include  <sstream>

class NetModule : public IMonitorModule
{
public:
	NetModule();
	NetModule(NetModule const &x);
	NetModule &operator=(NetModule const &x);
	~NetModule();

	void	getInfo(std::vector<std::string> &x) const;
};


#endif
