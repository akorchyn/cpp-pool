#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
	: Form("Robotomy Request", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &x)
	: Form(x)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &x)
{
	if (&x == this)
		return *this;
	Form::operator=(x);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &x) const
{
	Form::execute(x);
	std::cout << "* drilling noise *\n" << _target << " has been robotomized successfully 50% time,"
												   "the rest time its a failure" << std::endl;
}
