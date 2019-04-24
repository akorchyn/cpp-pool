#ifndef HELPER_OFFICEBLOCK_HPP
#define HELPER_OFFICEBLOCK_HPP

#include "Intern.hpp"
#include "Bureaucrat.hpp"

class OfficeBlock
{
public:
	OfficeBlock();
	OfficeBlock(Intern const &x, Bureaucrat const &execrat, Bureaucrat const &signcrat);
	~OfficeBlock();

	void	doBureaucracy(std::string const &form , std::string const &target) const;

	void setIntern(Intern const &intern);
	void setExecutor(Bureaucrat const &execrat);
	void setSigner(Bureaucrat const &signcrat);

private:
	Intern		*_intern;
	Bureaucrat	*_execrat;
	Bureaucrat	*_signcrat;
};

#endif
