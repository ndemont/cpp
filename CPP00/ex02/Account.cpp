#include "Account.hpp"
#include <iostream>

using namespace std;

Account::Account(int initial_deposit)
{
	_totalAmount = initial_deposit;
}

Account::~Account(void)
{
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
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
	cout <<	_nbAccounts << endl;
	cout << _totalAmount << endl;
	cout << _totalNbDeposits << endl;
	cout << _totalNbWithdrawals << endl;
}

void	Account::makeDeposit( int deposit )
{
	_totalAmount += deposit;
	_totalNbDeposits ++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal <= _totalAmount)
	{
		_totalAmount -= withdrawal;
		_totalNbWithdrawals ++;
		return true;
	}
	else
		return false;
}
	
int		Account::checkAmount( void ) const
{
	return _totalAmount;
}

void	Account::displayStatus( void ) const
{
	cout << _totalAmount << endl;
}