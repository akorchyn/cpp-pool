#ifndef RUSH01_OSMODULE_HPP
#define RUSH01_OSMODULE_HPP

#include "IMonitorModule.hpp"
#include <sstream>

class OsModule : public IMonitorModule
{
public:
	OsModule();
	OsModule(OsModule const &x);
	OsModule &operator=(OsModule const &x);
	~OsModule();

	void getInfo(std::vector<std::string> &info) const;
};


#endif
