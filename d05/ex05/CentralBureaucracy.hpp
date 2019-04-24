#ifndef HELPER_CENTRALBUREAUCRACY_HPP
#define HELPER_CENTRALBUREAUCRACY_HPP

#include "Bureaucrat.hpp"
#include "OfficeBlock.hpp"
#include "Form.hpp"

class CentralBureaucracy
{
public:
	CentralBureaucracy();
	CentralBureaucracy(CentralBureaucracy const &x);
	CentralBureaucracy &operator=(CentralBureaucracy const &x);
	~CentralBureaucracy();

	void	setBureaucracy(const Bureaucrat &x);
	void	doBureaucracy();
	void	queueUp(std::string const &target);

private:
	const static int	_maxSize = 20;
	OfficeBlock			_offices[_maxSize];
	std::string			_queue[_maxSize];
};


#endif
