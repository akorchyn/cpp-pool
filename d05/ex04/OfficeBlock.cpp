#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock() : _intern(NULL), _execrat(NULL), _signcrat(NULL)
{
}

OfficeBlock::OfficeBlock(Intern const &x, Bureaucrat const &execrat, Bureaucrat const &signcrat)
	: _intern(new Intern(x)), _execrat(new Bureaucrat(execrat)), _signcrat(new Bureaucrat(signcrat))
{
}

OfficeBlock::~OfficeBlock()
{
	delete _intern;
	delete _execrat;
	delete _signcrat;
}

void OfficeBlock::doBureaucracy(std::string const &form, std::string const &target) const
{
	Form *x;

	if (!_intern)
		throw std::runtime_error("Employ a intern.");
	else if (!_signcrat)
		throw std::runtime_error("Employ a signing Bureaucrat");
	else if (!_execrat)
		throw std::runtime_error("Employ a exec Bureaucrat");

	try
	{
		x = _intern->makeForm(form, target);
		_signcrat->signForm(*x);
		_execrat->executeForm(*x);
	}
	catch (std::runtime_error &error)
	{
		delete x;
		std::cout << error.what() << std::endl;
		throw std::runtime_error("Change something, amigo");
	}
	delete x;
}

void OfficeBlock::setIntern(Intern const &intern)
{

	_intern = new Intern(intern);
}

void OfficeBlock::setExecutor(Bureaucrat const &execrat)
{
	_execrat = new Bureaucrat(execrat);
}

void OfficeBlock::setSigner(Bureaucrat const &signcrat)
{
	_signcrat = new Bureaucrat(signcrat);
}
