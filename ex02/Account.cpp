/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:17:20 by osarsari          #+#    #+#             */
/*   Updated: 2023/12/18 13:05:30 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << \
		";deposits:" << _totalNbDeposits << ";withdrawals:" << \
		_totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << \
		";created" << std::endl;
}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << \
		";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int p_amount = this->_amount;
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;

	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << \
		p_amount << ";deposit:" << deposit << ";amount:" << this->_amount << \
		";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int p_amount = this->_amount;
	if (withdrawal > this->_amount)
	{
		this->_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << \
			p_amount << ";withdrawal:refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;

	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << \
		p_amount << ";withdrawal:" << withdrawal << ";amount:" << \
		this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << \
		std::endl;
	return true;
}

int Account::checkAmount(void) const
{
	return this->_amount;
}

void Account::displayStatus(void) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << \
		this->_amount << ";deposits:" << this->_nbDeposits << \
		";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	std::cout << "[" << ltm->tm_year + 1900 << std::setw(2) << \
		std::setfill('0') << ltm->tm_mon + 1 << std::setw(2) << \
		std::setfill('0') << ltm->tm_mday << "_" << std::setw(2) << \
		std::setfill('0') << ltm->tm_hour << std::setw(2) << \
		std::setfill('0') << ltm->tm_min << std::setw(2) << \
		std::setfill('0') << ltm->tm_sec << "] ";
}
