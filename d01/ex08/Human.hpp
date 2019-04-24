#ifndef HELPER_HUMAN_HPP
#define HELPER_HUMAN_HPP

#include <string>
#include <iostream>

class Human
{
private:
	void meleeAttack(std::string const &target);
	void rangedAttack(std::string const &target);
	void intimidatingShout(std::string const &target);

	std::string	_name[3];
	void (Human::*_t[3])(std::string const &);

public:
	Human();
	void 	action(std::string const & action_name, std::string const &target);
};


#endif
