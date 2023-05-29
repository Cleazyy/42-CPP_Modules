/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:12:02 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/29 09:14:00 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */

PhoneBook::PhoneBook(void) {}

PhoneBook::~PhoneBook(void) {}

/* ************************************************************************** */
/*                          Private Member functions                          */
/* ************************************************************************** */

void	PhoneBook::_printHeader(void)
{
	std::cout << MSG_SEPARTOR << std::endl;
	std::cout << "|" << std::setw(10) << "INDEX";
	std::cout << "|" << std::setw(10) << "FIRST NAME";
	std::cout << "|" << std::setw(10) << "LAST NAME";
	std::cout << "|" << std::setw(10) << "NICKNAME";
	std::cout << "|" << std::endl;
	std::cout << MSG_SEPARTOR << std::endl;
}

void	PhoneBook::_printList(void)
{
	this->_printHeader();
	for (int index = 0; index < 8; index++) {
		this->_contact[index].printElementList(index);
	}
}

bool	PhoneBook::_inputOnlyDigits(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i])) {
			return (false);
		}
	}
	return (true);
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

void	PhoneBook::addContact(void)
{
	static int index = 0;

	this->_contact[index].getSettings();
	index++;
	if (index == 8) {
		index = 0;
	}
}

void	PhoneBook::searchContact(void)
{
	std::string input;
	int index;

	this->_printList();
	while (1)
	{
		std::cout << MSG_SEARCH << "Enter contact index: ";
		std::getline(std::cin, input);
		if (input.empty() || this->_inputOnlyDigits(input) == false) {
			std::cout << MSG_ERROR << "Please enter a valid number." << std::endl;
			continue ;
		}
		index = std::atoi(input.c_str());
		if (index < 0 || index > 7) {
			std::cout << MSG_ERROR << "Pleaser enter an index between 0 and 7." << std::endl;
			continue ;
		}
		else {
			this->_contact[index].printContact(index);
			break ;
		}
	}
}
