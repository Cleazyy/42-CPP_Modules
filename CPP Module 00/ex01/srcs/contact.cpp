/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:15:56 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/09 22:31:05 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::getSettings(void)
{
	std::cout << MSG_CONTACT << "First name: ";
	std::getline(std::cin, _firstName);
	std::cout << MSG_CONTACT << "Last name: ";
	std::getline(std::cin, _lastName);
	std::cout << MSG_CONTACT << "Nickname: ";
	std::getline(std::cin, _nickName);
	std::cout << MSG_CONTACT << "Phone number: ";
	std::getline(std::cin, _phoneNumber);
	std::cout << MSG_CONTACT << "Darkest secret: ";
	std::getline(std::cin, _darkestSecret);
}

void	Contact::printHeaderPhoneBook(void)
{
	std::cout << MSG_SEPARTOR << std::endl;
	std::cout << "|" << std::setw(10) << "INDEX";
	std::cout << "|" << std::setw(10) << "FIRST NAME";
    std::cout << "|" << std::setw(10) << "LAST NAME";
    std::cout << "|" << std::setw(10) << "NICKNAME";
    std::cout << "|" << std::endl;
	std::cout << MSG_SEPARTOR << std::endl;
}

void	Contact::printPhoneBook(int index)
{
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << "Quentin";
    std::cout << "|" << std::setw(10) << "Fernendez";
    std::cout << "|" << std::setw(10) << "Cleazyy";
    std::cout << "|" << std::endl;
	std::cout << MSG_SEPARTOR << std::endl;
}