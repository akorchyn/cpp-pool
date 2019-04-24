#include "Logger.hpp"

int main()
{
	Logger      x("log.log");

	x.log("Console", "console example");
	x.log("File", "file example");
}
