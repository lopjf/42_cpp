#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

// PUBLIC

static int	getNbAccounts( void ) {
    return Account::_nbAccounts;
}
static int	getTotalAmount( void ) {
    return Account::_totalAmount;
}
static int	getNbDeposits( void ) {
    return Account::_totalNbDeposits;
}
static int	getNbWithdrawals( void ) {
    return Account::_totalNbWithdrawals;
}
static void	displayAccountsInfos( void ) {
    Account::_displayTimestamp();
    // std::cout << "index:" << Account::t._accountIndex;
    // std::cout << ";amount:" << Account::_amount;
    // std::cout << ";deposits:" << Account::_nbDeposits;
    // std::cout << ";withdrawals:" << Account::_nbWithdrawals << std::endl;
}

void	makeDeposit( int deposit ) {
    _amount += deposit;
    this->t._nbDeposits++;
}
bool	makeWithdrawal( int withdrawal ) {
    if (withdrawal > this->t._amount)
        false;
    this->t._nbWithdrawals++;
    true;
}
int		checkAmount( void ) const {
    return 0;
}
void	displayStatus( void ) const {
    
}


// PRIVATE

static void	_displayTimestamp( void ) {
    std::time_t currentTime = std::time(nullptr);
    struct std::tm *localTime = std::localtime(&currentTime);

    // Format the timestamp
    std::cout << "[" << std::put_time(localTime, "%Y%m%d_%H%M%S") << "] ";
}


Account::Account(int initial_deposit) : _amount(initial_deposit) {
    
    static int index = -1;
    index++;
    this->_accountIndex = index;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    _displayTimestamp();

    return;
}

Account::~Account(void) {

    return;
}