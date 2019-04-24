#ifndef RUSH01_DATEMONITOR_HPP
#define RUSH01_DATEMONITOR_HPP

#include "IMonitorModule.hpp"
#include <ctime>

class DateModule : public  IMonitorModule
{
public:
	DateModule();
	DateModule(DateModule const &x);
	DateModule &operator=(DateModule const &x);
	~DateModule();

	void getInfo(std::vector<std::string> &info) const;
};


#endif
