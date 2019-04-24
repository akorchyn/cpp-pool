#include "Form.hpp"

Form::Form() : _gradeToSign(0), _gradeToExecute(0)
{
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(0), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
}

Form::Form(Form const &x)
	: _name(x._name), _isSigned(x._isSigned), _gradeToSign(x._gradeToSign), _gradeToExecute(x._gradeToExecute), _target(x._target)
{
}

Form &Form::operator=(Form const &x)
{
	if (&x == this)
		return *this;
	_isSigned = x._isSigned;
	_target = x._target;
	return *this;
}

std::ostream &operator<<(std::ostream &s, Form const &x)
{
	s << x.getName() << ", form currently ";
	if (!x.getIsSigned())
		s << "not ";
	s << "signed. Mark to sign " << x.getGradeToSign() << ", mark to execute " << x.getGradeToExecute() << std::endl;
	return s;
}

void Form::beSigned(Bureaucrat const &x)
{
	if (x.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void Form::execute(Bureaucrat const &x) const
{
	if (x.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	else if (_isSigned == false)
		throw FormNotSigned();
}

Form::~Form()
{
}

const std::string &Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

/*
 * Exception Block
 */

Form::GradeTooHighException::GradeTooHighException() : std::exception()
{
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

Form::GradeTooHighException::GradeTooHighException(const Form::GradeTooHighException &x)
		: std::exception(x)
{
}

Form::GradeTooHighException &Form::GradeTooHighException::operator=(const Form::GradeTooHighException &x)
{
	static_cast<void>(x);
	return *this;
}

Form::GradeTooLowException &Form::GradeTooLowException::operator=(const Form::GradeTooLowException &x)
{
	static_cast<void>(x);
	return *this;
}

Form::GradeTooLowException::GradeTooLowException(const Form::GradeTooLowException &x)
		: std::exception(x)
{
}

Form::GradeTooLowException::GradeTooLowException() : std::exception()
{
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

Form::FormNotSigned::FormNotSigned() : std::exception()
{
}

Form::FormNotSigned::FormNotSigned(const Form::GradeTooHighException &x) : std::exception(x)
{
}

Form::FormNotSigned &Form::FormNotSigned::operator=(const Form::FormNotSigned &x)
{
	static_cast<void>(x);
	return *this;
}

const char *Form::FormNotSigned::what() const throw()
{
	return "Form not signed";
}
