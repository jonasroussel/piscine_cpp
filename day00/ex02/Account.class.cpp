/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:32:32 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 12:41:44 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.class.hpp"

/**
 * Static Variables
 */

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/**
 * Static Methods
 */

int     Account::getNbAccounts( void )
{
    return _nbAccounts;
}

int     Account::getTotalAmount( void )
{
    return _totalAmount;
}

int     Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

int     Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

void    Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout
    << "accounts:" << getNbAccounts()
    << ";total:" << getTotalAmount()
    << ";deposits:" << getNbDeposits()
    << ";withdrawals:" << getNbWithdrawals()
    << std::endl;
}

void    Account::_displayTimestamp( void )
{
    time_t _time = time(&_time);
	struct tm *date = localtime(&_time);

    int year = 1900 + date->tm_year;
    int mon = date->tm_mon + 1;
    int day = date->tm_mday;
    
    int hour = date->tm_hour;
    int min = date->tm_min;
    int sec = date->tm_sec;

    std::cout
    << "["
    << year
    << (mon < 10 ? "0" : "")
    << mon
    << (day < 10 ? "0" : "")
    << day
    << "_"
    << (hour < 10 ? "0" : "")
    << hour
    << (min < 10 ? "0" : "")
    << min
    << (sec < 10 ? "0" : "")
    << sec
    << "] ";
}

/**
 * Constructor & Destructor
 */

Account::Account( int initial_deposit )
{
    this->_accountIndex = getNbAccounts();
    this->_amount = initial_deposit;
    this->_nbWithdrawals = 0;
    this->_nbDeposits = 0;

    _displayTimestamp();
    std::cout
    << "index:" << this->_accountIndex
    << ";amount:" << this->_amount
    << ";created"
    << std::endl;
    
    _totalAmount += this->_amount;
    _nbAccounts++;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout
    << "index:" << this->_accountIndex
    << ";amount:" << this->_amount
    << ";closed"
    << std::endl;
}

/**
 * Public Methods
 */

void    Account::makeDeposit( int deposit )
{
    int p_amount = this->_amount;
    this->_amount += deposit;
    this->_nbDeposits++;

    _totalAmount += (this->_amount - p_amount);
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout
    << "index:" << this->_accountIndex
    << ";p_amount:" << p_amount
    << ";deposit:" << deposit
    << ";amount:" << this->_amount
    << ";nb_deposits:" << this->_nbDeposits
    << std::endl;
}

bool    Account::makeWithdrawal( int withdrawal )
{
    if (this->_amount < withdrawal)
    {
        _displayTimestamp();
        std::cout
        << "index:" << this->_accountIndex
        << ";p_amount:" << this->_amount
        << ";withdrawal:refused"
        << std::endl;
        
        return false;
    }
    else
    {
        int p_amount = this->_amount;
        this->_amount -= withdrawal;
        this->_nbWithdrawals++;

        _totalAmount -= (p_amount - this->_amount);
        _totalNbWithdrawals++;

        _displayTimestamp();
        std::cout
        << "index:" << this->_accountIndex
        << ";p_amount:" << p_amount
        << ";withdrawal:" << withdrawal
        << ";amount:" << this->_amount
        << ";nb_withdrawals:" << this->_nbWithdrawals
        << std::endl;

        return true;
    }
}

int     Account::checkAmount( void ) const
{
    std::cout << "checkAmount()" << std::endl;
    return 0;
}

void    Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout
    << "index:" << this->_accountIndex
    << ";amount:" << this->_amount
    << ";deposits:" << this->_nbDeposits
    << ";withdrawals:" << this->_nbWithdrawals
    << std::endl;
}
