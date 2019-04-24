#ifndef HELPER_BUREAUCRAT_HPP
#define HELPER_BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
public:
	class	GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();
		GradeTooHighException(GradeTooHighException const &x);
		GradeTooHighException &operator=(GradeTooHighException const &x);
		const char *what() const throw();
		virtual ~GradeTooHighException() throw() {};
	};
	class	GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();
		const char *what() const throw();
		GradeTooLowException &operator=(GradeTooLowException const &x);
		GradeTooLowException(GradeTooLowException const &x);
		virtual ~GradeTooLowException() throw() {};
	};

	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &x);
	Bureaucrat &operator=(Bureaucrat const &x);
	~Bureaucrat();

	void			increment();
	void			decrement();

	const std::string	&getName() const;
	int 				getGrade() const;

private:
	Bureaucrat();
	const std::string		_name;
	int						_grade;
};

std::ostream &operator<<(std::ostream &s, Bureaucrat const &x);

#endif
