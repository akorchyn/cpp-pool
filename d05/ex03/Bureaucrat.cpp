#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &x) : _name(x._name), _grade(x._grade)
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &x)
{
	if (this == &x)
		return *this;
	_grade = x._grade;
	return *this;
}

void Bureaucrat::executeForm(Form &form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executes " << form.getName() << std::endl;
	}
	catch (std::exception &x)
	{
		std::cout << _name << " cannot execute " << form.getName() << " because " << x.what() << std::endl;
	}

}

Bureaucrat::~Bureaucrat()
{
}

std::ostream &operator<<(std::ostream &s, Bureaucrat const &x)
{
	s << x.getName() << ", bureaucrat grade " << x.getGrade() << std::endl;
	return s;
}

const std::string &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}


void Bureaucrat::increment()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrement()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception &x)
	{
		std::cout << _name << " cannot sign " << form.getName() << " because " << x.what() << std::endl;
	}
}

/*
 * Exception Block
 */

Bureaucrat::GradeTooHighException::GradeTooHighException() : std::exception()
{
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const Bureaucrat::GradeTooHighException &x)
	: std::exception(x)
{
}

Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator=(const Bureaucrat::GradeTooHighException &x)
{
	static_cast<void>(x);
	return *this;
}

Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::operator=(const Bureaucrat::GradeTooLowException &x)
{
	static_cast<void>(x);
	return *this;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const Bureaucrat::GradeTooLowException &x)
	: std::exception(x)
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException() : std::exception()
{
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}
