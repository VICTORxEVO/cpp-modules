#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


int	Account::getNbAccounts(void)
{
    return (Account::_nbAccounts);
}
int	Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
    time_t now;
    std::tm _time;
    char buff[100];

	now = time(NULL);
    _time = *std::localtime(&now);
    std::strftime(buff, sizeof(buff),"[%Y%m%d_%H%M%S] ",&_time);
    std::cout << buff;
}

//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:" << Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
    this->_accountIndex = this->_nbAccounts;
    this->_nbAccounts += 1;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_totalAmount += initial_deposit;
    this->_amount = initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;
}
//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void    Account::makeDeposit(int deposit)
{
    if (deposit <= 0)
        return ;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "deposit:" << deposit << ";";

    this->_amount += deposit;
    this->_nbDeposits++;
    this->_totalNbDeposits++;
    this->_totalAmount += deposit;

    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}
//[19920104_091532] index:0;p_amount:47;withdrawal:refused
//[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool	Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->checkAmount() << ";";
    if (withdrawal > this->checkAmount())
    {
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    this->_amount -= withdrawal;
    this->_totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    this->_totalNbWithdrawals++;
    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}

int		Account::checkAmount(void) const
{
    return (this->_amount);
}
//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void	Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}