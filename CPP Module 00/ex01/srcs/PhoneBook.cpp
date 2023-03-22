/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:12:02 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/22 08:54:47 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::addContact(void)
{
	static int index = 0;

	_contact[index].getSettings();
	index++;
	if (index == 8)
		index = 0;
}

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
	_printHeader();
	for (int index = 0; index < 8; index++)
		_contact[index].printElementList(index);
}

bool	PhoneBook::_inputOnlyDigits(std::string input)
{
	bool onlyDigits;

	onlyDigits = true;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
		{
			onlyDigits = false;
			break ;
		}
	}
	return (onlyDigits);
}

void	PhoneBook::searchContact(void)
{
	std::string input;
	int			index;

	_printList();
	while (1)
	{
		std::cout << MSG_SEARCH << "Enter contact index: ";
		std::getline(std::cin, input);
		if (input.empty() || !_inputOnlyDigits(input))
		{
			std::cout << MSG_ERROR << "Please enter a valid number." << std::endl;
			continue ;
		}
		index = std::atoi(input.c_str());
		if (index < 0 || index > 7)
		{
			std::cout << MSG_ERROR << "Pleaser enter an index between 0 and 7." << std::endl;
			continue ;
		}
		else
		{
			_contact[index].printContact(index);
			break ;
		}
	}
}