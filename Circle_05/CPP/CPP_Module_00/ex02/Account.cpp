#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account( int initial_deposit )
    : _accountIndex(_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0)
{
    ++_nbAccounts;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << \
                 ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << \
                 ";amount:" << _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
    return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
    return _totalAmount;
}

int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts << \
                 ";total:" << _totalAmount << \
                 ";deposits:" << _totalNbDeposits << \
                 ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    int p_amount;

    p_amount = _amount;
    _amount += deposit;
    ++_nbDeposits;
    ++_totalNbDeposits;
    _totalAmount += deposit;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex << \
                 ";p_amount:" << p_amount << \
                 ";deposit:" << deposit << \
                 ";amount:" << _amount << \
                 ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    int p_amount;
    bool refused_flag;

    p_amount = _amount;
    if (p_amount < withdrawal)
    {
        refused_flag = true;
    }
    else
    {
        refused_flag = false;
        _amount -= withdrawal;
        ++_nbWithdrawals;
        ++_totalNbWithdrawals;
        _totalAmount -= withdrawal;
    }

    _displayTimestamp();
    std::cout << " index:" << _accountIndex << \
                 ";p_amount:" << p_amount;
    if (refused_flag)
    {
        std::cout << ";withdrawal:refused" << std::endl;
    }
    else
    {
        std::cout <<  ";withdrawal:" << withdrawal << \
                      ";amount:" << _amount << \
                      ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    }
    return !refused_flag;
}

int		Account::checkAmount( void ) const
{
    return _amount;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << \
                 ";amount:" << _amount << \
                 ";deposits:" << _nbDeposits << \
                 ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
    std::time_t time;
    std::tm* timeinfo;
    char buffer[20];

    std::time(&time);
    timeinfo = std::localtime(&time);

    std::strftime(buffer, 20, "%Y%m%d_%H%M%S", timeinfo);
    std::cout << "[" << buffer << "]";
}
