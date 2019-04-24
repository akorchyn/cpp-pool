#include "../includes/NetModule.hpp"

NetModule::NetModule()
{
}

NetModule::NetModule(__attribute__((unused))NetModule const &x)
{
}

NetModule &NetModule::operator=(__attribute__((unused))NetModule const &x)
{
	return *this;
}


NetModule::~NetModule()
{
}

void NetModule::getInfo(std::vector<std::string> &info) const
{
	std::stringstream output;
	std::string tmp;
	char buff[128];

	FILE* pipe = popen("nettop -m route -l1 | grep \"default -> en0\" | awk 'BEGIN{FS=\" \"} {print $7 $8 \" \" $9 $10}'", "r");
	while (fgets(buff, sizeof buff, pipe) != NULL) {
		output << buff;
	}
	pclose(pipe);
	while (std::getline(output, tmp, ' '))
		info.push_back(tmp);
}

