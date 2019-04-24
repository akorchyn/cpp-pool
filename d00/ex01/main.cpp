#include "contacts.h"
#include <iostream>
#include <string>

int main()
{
	contacts	contactList;

	while (1)
	{
		std::string		command;
		std::cout << "Enter a command (ADD, SEARCH, EXIT) : ";
		std::cin >> command;

		if (command == "ADD")
			contactList.add();
		else if (command == "SEARCH")
			contactList.search();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command" << std::endl;
	}
}