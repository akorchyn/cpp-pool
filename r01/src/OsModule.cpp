#include "../includes/OsModule.hpp"

OsModule::OsModule()
{
}

OsModule::OsModule(__attribute__((unused))OsModule const &x)
{
}

OsModule &OsModule::operator=(__attribute__((unused))OsModule const &x)
{
	return *this;
}

OsModule::~OsModule()
{
}

void OsModule::getInfo(std::vector<std::string> &info) const
{
	std::stringstream output;
	std::string tmp;
	char buff[128];

	FILE* pipe = popen("sw_vers", "r");
	while (fgets(buff, sizeof buff, pipe) != NULL) {
		output << buff;
	}
	pclose(pipe);
	while (std::getline(output, tmp, '\n'))
	{
		for(size_t pos = tmp.find('\t'); pos != std::string::npos; pos = tmp.find('\t'))
			tmp = tmp.replace(pos, 1, " ");
		info.push_back(tmp);
	}
}
