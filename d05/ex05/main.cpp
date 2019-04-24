#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"

int main()
{
	CentralBureaucracy x;

	x.doBureaucracy();

	x.queueUp("Bork");

	x.doBureaucracy();

	x.setBureaucracy(Bureaucrat("Joe", 34));
	x.setBureaucracy(Bureaucrat("Jimmy", 4));
	x.setBureaucracy(Bureaucrat("Andrey", 120));
	x.setBureaucracy(Bureaucrat("Kim", 17));
	x.setBureaucracy(Bureaucrat("Zabuza", 67));
	x.setBureaucracy(Bureaucrat("Joel", 47));
	x.setBureaucracy(Bureaucrat("Mark", 77));
	x.setBureaucracy(Bureaucrat("Milly", 98));
	x.setBureaucracy(Bureaucrat("Hermes", 1));
	x.setBureaucracy(Bureaucrat("Liviy", 22));
	x.setBureaucracy(Bureaucrat("Larry", 145));
	x.setBureaucracy(Bureaucrat("Lay", 1));
	x.setBureaucracy(Bureaucrat("Fame", 18));
	x.setBureaucracy(Bureaucrat("Linda", 1));
	x.setBureaucracy(Bureaucrat("Max", 4));
	x.setBureaucracy(Bureaucrat("Konstantin", 3));
	x.setBureaucracy(Bureaucrat("Dmitriy", 100));
	x.setBureaucracy(Bureaucrat("Artur", 1));
	x.setBureaucracy(Bureaucrat("Ivan", 34));
	x.setBureaucracy(Bureaucrat("Vanessa", 11));

	x.queueUp("Fork");
	x.queueUp("Mork");
	x.queueUp("Kork");
	x.queueUp("Lork");

	x.doBureaucracy();

}