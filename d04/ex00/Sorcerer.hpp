#ifndef HELPER_SORCERER_HPP
#define HELPER_SORCERER_HPP

#include <string>
#include <iostream>

#include "Victim.hpp"

class Sorcerer
{
private:
	std::string _name;
	std::string _title;

public:
	Sorcerer(std::string name, std::string title);
	Sorcerer(const Sorcerer &x);
	Sorcerer &operator=(const Sorcerer &x);
	~Sorcerer();
	const std::string &get_name() const;
	const std::string &get_title() const;

	void		polymorph(Victim const &x) const;
};

std::ostream	&operator<<(std::ostream &s, const Sorcerer &x);

#endif
