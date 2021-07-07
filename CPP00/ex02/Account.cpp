#include "Account.hpp"

Account::Account(int initial_deposit)
{
	_totalAmount = initial_deposit;
}

Account::~Account(void)
{
}

static int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

static int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

static int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

static int	Account::getNbWithdrawals(void)
{
	return (_nbWithdrawals);
}

static void	Account::displayAccountsInfos(void);
{
	cout <<	_nbAccounts << endl;
	cout << _totalAmount << endl;
	cout << _totalNbDeposits << endl;
	cout << _totalNbWithdrawals << endl;
	cout << _accountIndex << endl;
	cout << _amount << endl;
	cout << _nbDeposits << endl;
	cout << _nbWithdrawals << endl;
}

void	Account::makeDeposit( int deposit )
{
	_totalAmount += deposit;
	_totalNbDeposits ++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_totalAmount -= withdrawal;
	_totalNbWithdrawals ++;
	return ((_totalAmount));
}
	
int		Account::checkAmount( void ) const
{
	return (_totalAmount);
}

void	Account::displayStatus( void ) const;
{
	cout << _totalAmount << endl;
}