#ifndef RUSH01_HOSTNAMEUSERNAMEMONITOR_HPP
#define RUSH01_HOSTNAMEUSERNAMEMONITOR_HPP

#include "IMonitorModule.hpp"
#include <zconf.h>
#include <pwd.h>

class HostnameUsernameModule : public IMonitorModule
{
public:
	HostnameUsernameModule();
	HostnameUsernameModule(HostnameUsernameModule const &x);
	HostnameUsernameModule &operator=(HostnameUsernameModule const &x);
	~HostnameUsernameModule();

	void getInfo(std::vector<std::string> &info) const;
};


#endif
