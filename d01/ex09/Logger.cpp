#include "Logger.hpp"

void Logger::logToConsole(const std::string &str)
{
	std::cout << makeLogEntry(str) << std::endl;
}

void Logger::logToFile(const std::string &str)
{
	file << makeLogEntry(str) << std::endl;
}

Logger::~Logger()
{
	file.close();
}

Logger::Logger(const std::string &filename)
{
	file.open(filename);
	if (!file)
		std::cerr << "Can't create file" << std::endl;
}

std::string Logger::makeLogEntry(const std::string &msg)
{
	return ("[LOG Start] Message : " + msg + " [LOG end]");
}

void Logger::log(std::string const &dest, std::string const &message)
{
	void			(Logger::*func[2])(const std::string &) = {&Logger::logToConsole, &Logger::logToFile};
	std::string		type[2] = {"Console", "File"};

	for (int i = 0; i < 2; i++)
		if (type[i] == dest)
			(this->*func[i])(message);
}
