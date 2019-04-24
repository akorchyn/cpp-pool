#include "../includes/DateModule.hpp"

DateModule::DateModule()
{
}

DateModule::DateModule(__attribute__((unused))DateModule const &x)
{
}

DateModule &DateModule::operator=(__attribute__((unused))DateModule const &x)
{
	return *this;
}

DateModule::~DateModule()
{
}

void DateModule::getInfo(std::vector<std::string> &info) const
{
	char 	timeString[255];
	time_t	rawTime;
	tm		*tmStruct;

	time(&rawTime);

	tmStruct = localtime(&rawTime);
	info.push_back("The current date is : ");
	strftime(timeString, 255, "%c", tmStruct);
	info.push_back(timeString);
}