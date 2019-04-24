#include "Account.class.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int		Account::_totalNbDeposits = 0;
int		Account::_totalAmount = 0;
int		Account::_nbAccounts = 0;
int		Account::_totalNbWithdrawals = 0;

int		Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int		Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int		Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int		Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void		Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount;
	std::cout << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_amount = initial_deposit;
	_nbWithdrawals = 0;
	_nbDeposits = 0;
	_totalAmount += initial_deposit;
	_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	_nbAccounts--;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void		Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	_nbDeposits++;
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool		Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int			Account::checkAmount() const
{
	return (_amount);
}

void		Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;

}

void Account::_displayTimestamp()
{
	time_t currentTime = std::time(NULL);
	tm  *localTime = std::localtime(&currentTime);

	std::cout << "[" <<
			  localTime->tm_year + 1900 <<
			  std::setw(2) << std::setfill('0') << localTime->tm_mon <<
			  std::setw(2) << std::setfill('0') << localTime->tm_mday <<
			  "_" <<
			  std::setw(2) << std::setfill('0') << localTime->tm_hour <<
			  std::setw(2) << std::setfill('0') << localTime->tm_min <<
			  std::setw(2) << std::setfill('0') << localTime->tm_sec
			  << "] ";
}