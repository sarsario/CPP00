/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:50:38 by osarsari          #+#    #+#             */
/*   Updated: 2023/10/26 11:42:20 by osarsari         ###   ########.fr       */
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

void PhoneBook::searchContact(int index)
{
	if (index < 0 || index > 7)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	// if (this->_contacts[index] == NULL)
	// {
	// 	std::cout << "No contact at this index." << std::endl;
	// 	return;
	// }
}