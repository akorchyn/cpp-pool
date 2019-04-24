#ifndef HELPER_ROBOTOMYREQUESTFORM_HPP
#define HELPER_ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &x);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &x);
	~RobotomyRequestForm();

	void	execute(Bureaucrat const &x) const;
private:
	RobotomyRequestForm();
};


#endif
