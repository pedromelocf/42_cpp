#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account ( int initial_deposit ) : _accountIndex ( _nbAccounts ) , _amount ( _totalAmount )
		, _nbDeposits ( _totalNbDeposits ), _nbWithdrawals( _totalNbWithdrawals ) {

	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex ; 
	std::cout << ";amount:" << _amount ;
	std::cout << ";created" << std::endl;
}

Account::~Account ( void ) {

	_displayTimestamp();
	std::cout << "index:" << _accountIndex ;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;

}

void	Account::makeDeposit ( int deposit ) {

	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits += 1;
	this->_totalNbDeposits +=1;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex ;
	std::cout << ";p_amount:" << this->_amount - deposit;
	std::cout << ";deposit:" <<	deposit;
	std::cout << ";amount:" << this->_amount ;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;

}

bool	Account::makeWithdrawal ( int withdrawal ) {

	if ( checkAmount () < withdrawal )
	{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex;
		std::cout << ";p_amount:" << this->_amount ;
		std::cout << ";withdrawal:refused" << std::endl;
		return ( false );
	}

	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals +=1;
	this->_totalNbWithdrawals += 1;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount + withdrawal;
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;

	return ( true );
	
}

int		Account::checkAmount ( void ) const {
	return (this->_amount);
}

void	Account::displayStatus ( void ) const {

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;

}

void	Account::displayAccountsInfos ( void ) {

	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;

}


void	Account::_displayTimestamp ( void ) {

	time_t	  cur_time;
	struct tm*  time_info;
	char		buff[16];

	std::time(&cur_time);
	time_info = std::localtime(&cur_time);
	std::strftime(buff, sizeof(buff), "%Y%m%d_%H%M%S",time_info);
	std::cout << "[" << buff << "] ";

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
