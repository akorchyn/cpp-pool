#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int main()
{

	Intern idiotOne;
	Bureaucrat Hermes = Bureaucrat("Hermes Conrad", 37);
	Bureaucrat bob("Bobby Bobson", 123);

	OfficeBlock ob;

	try
	{
		ob.doBureaucracy("shrubbery creation", "door");
	}
	catch (std::exception &x)
	{
		std::cout << x.what() << std::endl;
	}

	ob.setIntern(idiotOne);

	try
	{
		ob.doBureaucracy("shrubbery creation", "door");
	}
	catch (std::exception &x)
	{
		std::cout << x.what() << std::endl;
	}

	ob.setSigner(bob);

	try
	{
		ob.doBureaucracy("shrubbery creation", "door");
	}
	catch (std::exception &x)
	{
		std::cout << x.what() << std::endl;
	}

	ob.setExecutor(Hermes);

	try
	{
		ob.doBureaucracy("shrubbery creation", "door");
	}
	catch (std::exception &x)
	{
		std::cout << x.what() << std::endl;
	}

	try
	{
		ob.doBureaucracy("xx", "door");
	}
	catch (std::exception &x)
	{
		std::cout << x.what() << std::endl;
	}

}