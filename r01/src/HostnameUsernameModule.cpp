#include "../includes/HostnameUsernameModule.hpp"

HostnameUsernameModule::HostnameUsernameModule()
{
}

HostnameUsernameModule::HostnameUsernameModule(__attribute__((unused))HostnameUsernameModule const &x)
{
}

HostnameUsernameModule &HostnameUsernameModule::operator=(__attribute__((unused))HostnameUsernameModule const &x)
{
	return *this;
}

HostnameUsernameModule::~HostnameUsernameModule()
{
}

void HostnameUsernameModule::getInfo(std::vector<std::string> &info) const
{
	char			hostname[512];
	std::string		username(getpwuid(geteuid())->pw_name);

	gethostname(hostname, 512);
	info.push_back(std::string("Hostname : ") + hostname);
	info.push_back("Username : " + username);
}
