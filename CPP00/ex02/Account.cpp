#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <time.h>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	_amount = initial_deposit;
	Account::_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:"<< Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"; 
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";"; 
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	_amount += deposit;
	_nbDeposits++;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (withdrawal <= _amount)
	{
		std::cout << "index:" << _accountIndex << ";"; 
		std::cout << "p_amount:" << _amount << ";";
		std::cout << "withdrawal:" << withdrawal << ";"; 
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		std::cout << "amount:" << _amount << ";";
		Account::_totalNbWithdrawals++;
		_nbWithdrawals++;
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
	else
	{
		std::cout << "index:" << _accountIndex << ";"; 
		std::cout << "p_amount:" << _amount << ";";
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
}
	
int		Account::checkAmount( void ) const
{
	return _amount;
}

void	Account::_displayTimestamp( void )
{
	std::time_t result = std::time(NULL);
    struct tm *timeinfo= std::localtime(&result);
	std::cout << "[20" << timeinfo->tm_year - 100;
	if (timeinfo->tm_mon + 1 < 10)
		std::cout << "0";
	std::cout << timeinfo->tm_mon + 1;
	if (timeinfo->tm_mday < 10)
		std::cout << "0";
	std::cout << timeinfo->tm_mday << "_";
	if (timeinfo->tm_hour < 10)
		std::cout << "0";
	std::cout << timeinfo->tm_hour;
	if (timeinfo->tm_min < 10)
		std::cout << "0";
	std::cout << timeinfo->tm_min;
	if (timeinfo->tm_sec < 10)
		std::cout << "0";
	std::cout << timeinfo->tm_sec << "] ";
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:"<< _amount << ";";
	std::cout << "deposits:"<< _nbDeposits << ";";
	std::cout << "withdrawals:"<< _nbWithdrawals << std::endl;
}
