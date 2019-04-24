#ifndef HELPER_INTERN_HPP
#define HELPER_INTERN_HPP

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern const &x);
	Intern &operator=(Intern const &x);
	~Intern();

	Form	*makeForm(std::string const &form, std::string const &target);
};


#endif
