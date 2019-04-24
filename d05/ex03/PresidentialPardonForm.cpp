#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
	: Form("Presidential Pardon", 25, 5)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &x)
	: Form(x)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &x)
{
	if (this == &x)
		return *this;
	Form::operator=(x);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &x) const
{
	Form::execute(x);
	std::cout << _target << " has been pardoned by Zafod Beebbrox" << std::endl;
}
