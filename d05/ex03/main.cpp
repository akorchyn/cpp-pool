#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	try {
		Intern someRandomIntern;
		Bureaucrat	artur("artur", 1);

		Form *pform = someRandomIntern.makeForm("presidential pardon", "vasyok");
		Form *sform = someRandomIntern.makeForm("shrubbery creation", "filename");
		Form *rform = someRandomIntern.makeForm("robotomy request", "ivanenko");
//		Form *null = someRandomIntern.makeForm("ss", "yy");   uncomment to get exception

		artur.signForm(*pform);
		artur.signForm(*sform);
		artur.signForm(*rform);
//		if (!null)
//			std::cout << "null is null" << std::endl;
		delete pform;
		delete sform;
		delete rform;
	}
	catch (std::exception &x)
	{
		std::cout << x.what() << std::endl;
	}
}