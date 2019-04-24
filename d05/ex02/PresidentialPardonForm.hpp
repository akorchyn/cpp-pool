#ifndef HELPER_PRESIDENTIALPARDONFORM_HPP
#define HELPER_PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(PresidentialPardonForm const &x);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &x);
	~PresidentialPardonForm();

	void	execute(Bureaucrat const &x) const;

private:
	PresidentialPardonForm();
};


#endif
