/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:12:02 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/10 18:41:03 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
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
	for (int i = 0; i < 8; i++)
		_contact[i].printListElement(i);
}

void	PhoneBook::addContact(void)
{
	static int	i = 0;

	_contact[i].getSettings();
	i++;
	if (i == 8)
		i = 0;
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
		index = std::atoi(input.c_str());
		if (index < 0 || index > 7)
			std::cout << MSG_ERROR << "Enter an index between 0 and 7." << std::endl;
		else
		{
			_contact[index].printContact(index);
			break ;
		}	
	}
}