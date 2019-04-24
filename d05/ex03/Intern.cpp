#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &x)
{
	*this = x;
}

Intern &Intern::operator=(Intern const &x)
{
	static_cast<void>(x);
	return *this;
}

Intern::~Intern()
{
}

Form *Intern::makeForm(std::string const &form, std::string const &target)
{
	Form	*x;

	if (form == "robotomy request")
		x = new RobotomyRequestForm(target);
	else if (form == "presidential pardon")
		x = new PresidentialPardonForm(target);
	else if (form == "shrubbery creation")
		x = new ShrubberyCreationForm(target);
	else
	{
		std::cout << "Can't find the form" << std::endl;
		throw std::runtime_error("Form not found");
	}
	std::cout << "Intern creates " << x->getName() << std::endl;
	return x;
}


