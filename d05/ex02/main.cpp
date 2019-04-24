#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	try {
		Bureaucrat	kostya("Kostya", 50);
		Bureaucrat	artur("artur", 1);
		PresidentialPardonForm pform("Dmitro");
		ShrubberyCreationForm  sform("house");
		RobotomyRequestForm	   rform("some stupid gut");

		artur.signForm(pform);
		artur.executeForm(sform);
		kostya.executeForm(sform);;
		kostya.signForm(sform);
		kostya.signForm(rform);
		kostya.executeForm(sform);
		kostya.executeForm(pform);
		kostya.executeForm(rform);
		artur.executeForm(pform);
	}
	catch (std::exception &x)
	{
		std::cout << x.what() << std::endl;
	}
}