/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:12:02 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/09 22:16:58 by fluchten         ###   ########.fr       */
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
	_contact->printHeaderPhoneBook();
	for (int i = 1; i <= 8; i++)
		_contact[i].printPhoneBook(i);
}