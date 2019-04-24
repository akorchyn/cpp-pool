#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy()
{
	for (int i = 0; i < CentralBureaucracy::_maxSize; i++)
	{
		_offices[i] = OfficeBlock();
		_queue[i] = std::string();
	}
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const &x)
{
	*this = x;
}

CentralBureaucracy &CentralBureaucracy::operator=(CentralBureaucracy const &x)
{
	if (&x == this)
		return *this;
	for (int i = 0; i < CentralBureaucracy::_maxSize; i++)
	{
		_offices[i] = OfficeBlock();
		if (x._offices[i].getIntern())
			_offices[i].setIntern(*x._offices[i].getIntern());
		if (x._offices[i].getExecutor())
			_offices[i].setExecutor(*x._offices[i].getExecutor());
		if (x._offices[i].getSigner())
			_offices[i].setSigner(*x._offices[i].getSigner());
		_queue[i] = x._queue[i];
	}
	return *this;
}

CentralBureaucracy::~CentralBureaucracy()
{
}

void CentralBureaucracy::setBureaucracy(const Bureaucrat &x)
{
	for (int i = 0; i < CentralBureaucracy::_maxSize; i++)
	{
		if (_offices[i].getIntern() == NULL)
			_offices[i].setIntern(Intern());
		if (_offices[i].getSigner() == NULL)
		{
			_offices[i].setSigner(x);
			std::cout << "Welcome " << x.getName() << ". You are new Signer" << std::endl;
			return ;
		}
		else if (_offices[i].getExecutor() == NULL)
		{
			_offices[i].setExecutor(x);
			std::cout << "Welcome " << x.getName() << ". You are new Executor" << std::endl;
			return ;
		}
	}
	std::cout << "All offices are full. Sorry" << std::endl;
}

void CentralBureaucracy::queueUp(std::string const &target)
{
	for (int i = 0; i < CentralBureaucracy::_maxSize; i++)
		if (_queue[i].empty())
		{
			_queue[i] = target;
			std::cout << "Successfully added." << std::endl;
			return ;
		}
	std::cout << "Queue is full. Try next time" << std::endl;
}

void CentralBureaucracy::doBureaucracy()
{
	std::string	forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	if (_queue[0].empty())
	{
		std::cout << "No task" << std::endl;
		return ;
	}
	for (int i = 0, office = 0; !_queue[i].empty() && i < CentralBureaucracy::_maxSize; i++, office++)
	{
		try
		{
			if (!_offices[i].getSigner() || !_offices->getExecutor() || !_offices->getIntern())
				office = 0;
			_offices[office].doBureaucracy(forms[rand() % 3], _queue[i]);
			_queue[i].clear();
		}
		catch (std::exception &x)
		{
			if (office == 0)
			{
				std::cout << "Sorry, but offices are not full" << std::endl;
				return;
			}
			else
			{
				std::cout << "Damn, that office can't do this task. Maybe next? :)" << std::endl;
				i--;
			}
		}
	}
	std::cout << "Done" <<  std::endl;
}
