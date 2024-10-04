#include "Account.hpp"
#include <iostream>
#include <string>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account ( int initial_deposit ) : _accountIndex ( _nbAccounts ) , _amount ( _totalAmount )
		, _nbDeposits ( _totalNbDeposits ), _nbWithdrawals( _totalNbWithdrawals ) {

	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;

	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;

}

Account::~Account ( void ) {
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::makeDeposit ( int deposit ) {

	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits += 1;
	this->_totalNbDeposits +=1;

	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit << ";deposit:" << 
		deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;

}

bool	Account::makeWithdrawal ( int withdrawal ) {

	if ( this->_amount < withdrawal )
	{
		std::cout << "index:" << this->_accountIndex  << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
		return ( false );
	}

	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals +=1;
	this->_totalNbWithdrawals += 1;

	std::cout << "index:" << this->_accountIndex  << ";p_amount:" << this->_amount + withdrawal << ";withdrawal:" << withdrawal
		<< ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;

	return ( true );
	
}

int		Account::checkAmount ( void ) const {
	return (this->_amount);
}

void	Account::displayStatus ( void ) const {

	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << 
		this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;

}

void	Account::_displayTimestamp ( void ) {
	std::cout << "OI" << std::endl;
}

int		Account::getNbAccounts ( void ) {
	return ( _nbAccounts );
}
int		Account::getTotalAmount ( void ) {
	return ( _totalAmount );
}
int		Account::getNbDeposits ( void ) {
	return ( _totalNbDeposits );
}
int		Account::getNbWithdrawals ( void ) {
	return ( _totalNbWithdrawals );
}

void	Account::displayAccountsInfos ( void ) {

	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << 
		getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;

}
