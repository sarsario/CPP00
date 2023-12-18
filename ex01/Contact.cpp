/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:47:32 by osarsari          #+#    #+#             */
/*   Updated: 2023/12/18 09:05:24 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

std::string Contact::getFirstName(void) const
{
	return (this->_firstName);
}

void Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}

std::string Contact::getLastName(void) const
{
	return (this->_lastName);
}

void Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

std::string Contact::getNickname(void) const
{
	return (this->_nickname);
}

void Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;
}

std::string Contact::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

std::string Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}
