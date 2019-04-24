#include "contacts.h"

contacts::contacts() : _size(0)
{}

string	contacts::get_info(const string &x) const
{
	string	result;

	std::cout << "Please enter " << x << ": ";
	std::cin >> result;
	return (result);
}

void	contacts::printDetailedInfo(int index) const
{
	if (index < 0 || index >= _size)
	{
		std::cout << "Invalid input." << std::endl;
		return ;
	}
	std::cout << "First name:      " << _base[index][firstName] << std::endl;
	std::cout << "Last name:       " << _base[index][lastName] << std::endl;
	std::cout << "Nickname:        " << _base[index][nickname] << std::endl;
	std::cout << "Login:           " << _base[index][login] << std::endl;
	std::cout << "Address:         " << _base[index][postalAddress] << std::endl;
	std::cout << "Email:           " << _base[index][email] << std::endl;
	std::cout << "Mobile:          " << _base[index][phoneNumber] << std::endl;
	std::cout << "Birthday:        " << _base[index][birthday] << std::endl;
	std::cout << "Favorite meal:   " << _base[index][favoriteMeal] << std::endl;
	std::cout << "Underwear color: " << _base[index][underwearColor] << std::endl;
	std::cout << "Darkest secret:  " << _base[index][darkestSecret] << std::endl;
}

string		contacts::toPrint(int index, int line) const
{
	string start = "";

	if (_base[index][line].size() <= _widthInTable)
		return (_base[index][line]);
	for (int i = 0; i < _widthInTable - 1; i++)
		start += _base[index][line][i];
	start += ".";
	return (start);
}

void		contacts::print() const
{
	{
		for (int count = 4 * _widthInTable + 5; count; count--)
			std::cout << '_';
		std::cout << std::endl;
		std::cout << '|' << std::setw(_widthInTable) << "Index" << '|';
		std::cout << std::setw(_widthInTable) << "First name" << '|';
		std::cout << std::setw(_widthInTable) << "Last name" << '|';
		std::cout << std::setw(_widthInTable) << "Nickname" << '|' << std::endl;
		for (int count = 4 * _widthInTable + 5; count; count--)
			std::cout << '-';
		std::cout << std::endl;
		for (int index = 0; index < _size; index++)
		{
			std::cout << '|' << std::setw(_widthInTable) << index << '|';
			std::cout << std::setw(_widthInTable) << toPrint(index, firstName) << '|';
			std::cout << std::setw(_widthInTable) << toPrint(index, lastName) << '|';
			std::cout << std::setw(_widthInTable) << toPrint(index, nickname) << '|' << std::endl;
		}
		for (int count = 4 * _widthInTable + 5; count; count--)
			std::cout << '-';
		std::cout << std::endl;
	}
}

void		contacts::add()
{
	if (_size == _max_size)
	{
		std::cout << "Already full. More in new version... Soon..." << std::endl;
		return ;
	}
	_base[_size][firstName] = get_info("first name");
	_base[_size][lastName] = get_info("last name");
	_base[_size][nickname] = get_info("nickname");
	_base[_size][login] = get_info("login");
	_base[_size][postalAddress] = get_info("postal address");
	_base[_size][email] = get_info("email");
	_base[_size][phoneNumber] = get_info("phone number");
	_base[_size][birthday] = get_info("birthday date");
	_base[_size][favoriteMeal] = get_info("favorite meal");
	_base[_size][underwearColor] = get_info("underwear color");
	_base[_size][darkestSecret] = get_info("darkest secret");
	_size++;
}

void		contacts::search() const
{
	int n = 0;

	if (_size == 0)
	{
		std::cout << "Contacts not found" << std::endl;
		return ;
	}
	print();
	std::cout << "Enter index to get information: ";
	if (!(std::cin >> n))
	{
		std::cout << "Wrong index" << std::endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		return ;
	}
	printDetailedInfo(n);
}