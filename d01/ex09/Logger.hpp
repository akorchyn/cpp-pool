#ifndef HELPER_LOGGER_HPP
#define HELPER_LOGGER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>

class Logger
{
private:
	void logToConsole(const std::string &str);
	void logToFile(const std::string &str);
	std::string makeLogEntry(const std::string &msg);
	std::ofstream	file;

public:
	Logger(const std::string &filename);
	void	log(std::string const &dest, std::string const & message);
	~Logger();
};


#endif //HELPER_LOGGER_HPP
