/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:50:38 by osarsari          #+#    #+#             */
/*   Updated: 2023/12/18 10:02:57 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void PhoneBook::addContact(Contact contact)
{
	if (this->_index == 8)
		this->_index = 0;
	this->_contacts[this->_index] = contact;
	this->_index++;
}

std::string PhoneBook::truncate(std::string str) const
{
	std::string truncated;

	if (str.length() > 10)
	{
		truncated = str.substr(0, 9);
		truncated.append(".");
	}
	else
		truncated = str;
	return (truncated);
}

void PhoneBook::displayContacts(void) const
{
	std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << \
		"First name" << "|" << std::setw(10) << "Last name" << "|" << \
		std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < this->_index; i++)
	{
		std::cout << std::setw(10) << i << "|" << \
			std::setw(10) << \
			truncate(this->_contacts[i].getFirstName()) << "|" << \
			std::setw(10) << \
			truncate(this->_contacts[i].getLastName()) << "|" << \
			std::setw(10) << \
			truncate(this->_contacts[i].getNickname()) << std::endl;
	}
}

void PhoneBook::searchContact(int index)
{
	if (index < 0 || index > 7)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	if (this->_contacts[index].getFirstName().empty())
	{
		std::cout << "No contact at this index." << std::endl;
		return;
	}
	std::cout << "First name: " << this->_contacts[index].getFirstName() \
		<< std::endl;
	std::cout << "Last name: " << this->_contacts[index].getLastName() \
		<< std::endl;
	std::cout << "Nickname: " << this->_contacts[index].getNickname() \
		<< std::endl;
	std::cout << "Phone number: " << this->_contacts[index].getPhoneNumber() \
		<< std::endl;
}
