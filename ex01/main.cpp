/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:06:36 by osarsari          #+#    #+#             */
/*   Updated: 2023/12/18 09:55:13 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string getInput(std::string prompt)
{
	std::string input;

	std::cout << prompt << ": ";
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Please enter a valid input: " << std::endl;
		std::cout << prompt << ": ";
		std::getline(std::cin, input);
	}
	std::cout << std::endl;
	return (input);
}

void addContact(PhoneBook *phoneBook)
{
	Contact contact;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	firstName = getInput("First name");
	contact.setFirstName(firstName);
	lastName = getInput("Last name");
	contact.setLastName(lastName);
	nickname = getInput("Nickname");
	contact.setNickname(nickname);
	phoneNumber = getInput("Phone number");
	contact.setPhoneNumber(phoneNumber);
	darkestSecret = getInput("Darkest secret");
	contact.setDarkestSecret(darkestSecret);
	phoneBook->addContact(contact);
}

void searchContact(PhoneBook *phoneBook)
{
	std::string input;
	int index;

	phoneBook->displayContacts();
	input = getInput("Index");
	while (input.length() > 1 || !std::isdigit(input[0]))
	{
		std::cout << "Please enter a valid index: " << std::endl;
		input = getInput("Index");
	}
	index = std::stoi(input);
	phoneBook->searchContact(index);
}

int main(void)
{
	PhoneBook phoneBook;
	std::string input;

	std::cout << "Welcome to your phonebook!" << std::endl;
	while (1)
	{
		input = getInput("Please enter a command (ADD, SEARCH or EXIT)");
		if (input == "ADD")
			addContact(&phoneBook);
		else if (input == "SEARCH")
			searchContact(&phoneBook);
		else if (input == "EXIT")
			break;
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}
