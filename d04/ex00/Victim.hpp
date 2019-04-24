#ifndef HELPER_VICTIM_HPP
#define HELPER_VICTIM_HPP

#include <string>
#include <iostream>

class Victim
{
protected:
	std::string _name;

public:
	Victim(const std::string name);
	Victim(const Victim &x);
	Victim &operator=(const Victim &x);
	~Victim();
	const std::string	&get_name() const;
	virtual void		getPolymorphed() const;
};

std::ostream &operator<<(std::ostream &s, const Victim &x);

#endif
