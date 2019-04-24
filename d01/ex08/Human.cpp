#include "Human.hpp"


void Human::meleeAttack(std::string const &target)
{
	std::cout << "Attacked with spear to " << target << std::endl;
}

void Human::rangedAttack(std::string const &target)
{
	std::cout << "Throw spear to " << target << std::endl;
}

void Human::intimidatingShout(std::string const &target)
{
	std::cout << "Intimidating shout to " << target << std::endl;
}

void Human::action(std::string const &action_name, std::string const &target)
{
	int i;
	for (i = 0; _name[i] != action_name && i < 3; i++)
		;
	while (i < 3)
	{
		(this->*_t[i])(target);
		break ;
	}
}

Human::Human()
{
	_t[0] = &Human::meleeAttack;
	_t[1] = &Human::rangedAttack;
	_t[2] = &Human::intimidatingShout;
	_name[0] = "meleeAttack";
	_name[1] = "rangedAttack";
	_name[2] = "intimidatingShout";
}

