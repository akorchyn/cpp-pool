#ifndef CPP_POOL_CONTACTS_H
#define CPP_POOL_CONTACTS_H

#include <string>
#include <iostream>
#include <iomanip>

using std::string;

enum
{
	firstName,
	lastName,
	nickname,
	login,
	postalAddress,
	email,
	phoneNumber,
	birthday,
	favoriteMeal,
	underwearColor,
	darkestSecret
};

class contacts
{
private:
	static const int	_max_size = 8;
	static const int	_linesIn_base = 11;
	static const int	_widthInTable = 10;
	string		_base[_max_size][_linesIn_base];
	int			_size;

	void	print(void) const;
	string	get_info(const string &x) const;
	string	toPrint(int index, int line) const;
	void	printDetailedInfo(int index) const;


public:
	contacts();
	void	add(void);
	void	search(void) const;
};


#endif //CPP_POOL_CONTACTS_H
