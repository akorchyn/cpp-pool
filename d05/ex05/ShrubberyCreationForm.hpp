#ifndef HELPER_SHRUBBERYCREATIONFORM_HPP
#define HELPER_SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &x);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &x);
	~ShrubberyCreationForm();

	void		execute(Bureaucrat const &x) const;

private:
	ShrubberyCreationForm();
};


#endif
