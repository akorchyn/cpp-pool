#ifndef HELPER_FORM_HPP
#define HELPER_FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
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

	Form(std::string const &name, int gradeToSign, int gradeToExecute);
	Form(Form const &x);
	Form &operator=(Form const &x);
	virtual ~Form();

	const std::string		&getName() const;
	bool					getIsSigned() const;
	int						getGradeToSign() const;
	int						getGradeToExecute() const;

	void					beSigned(Bureaucrat const &x);

private:
	Form();
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int 			_gradeToExecute;
};

std::ostream			&operator<<(std::ostream &s, Form const &x);

#endif
