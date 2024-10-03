#include "Account.hpp"

static int	_nbAccounts = 0;
static int	_totalAmount = 0;
static int	_totalNbDeposits = 0;
static int	_totalNbWithdrawals = 0;

Account::Account ( int initial_deposit ) : _accountIndex ( _nbAccounts )
		, _amount ( _totalAmount ), _nbDeposits ( _totalNbDeposits ),
		_nbWithdrawals( _totalNbWithdrawals ) {

}

Account::~Account ( void ) {

}

void	Account::makeDeposit ( int deposit ) {

}

bool	Account::makeWithdrawal ( int withdrawal ) {

}

int		Account::checkAmount ( void ) const {

}

void	Account::displayStatus ( void ) const {

}

static void	Account::displayAccountsInfos( void ) {

}

static void	Account::_displayTimestamp( void ) {

}