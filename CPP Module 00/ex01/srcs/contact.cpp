/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:15:56 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/10 20:27:00 by fluchten         ###   ########.fr       */
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

void	Contact::_init(void)
{
	_firstName = "";
    _lastName = "";
    _nickName = "";
    _phoneNumber = "";
    _darkestSecret = "";
}

bool		Contact::_isPhoneNumber(std::string phoneNumber)
{
	bool onlyDigits;

	onlyDigits = true;
	for (size_t i = 0; i < phoneNumber.length(); i++)
	{
		if (!isdigit(phoneNumber[i]))
		{
			onlyDigits = false;
			break ;
		}
	}
	return (onlyDigits);
}

std::string	Contact::_resizeString(std::string str)
{
	std::string res;

	if (str.length() <= 10)
		res = str;
	else
	{
		res = str.substr(0, 9);
		res.replace(9, 1, ".");
	}
	return (res);
}

void	Contact::getSettings(void)
{
	_init();
	while (_firstName.empty())
	{
		std::cout << MSG_ADD << "First name: ";
		std::getline(std::cin, _firstName);
	}
	while (_lastName.empty())
	{
		std::cout << MSG_ADD << "Last name: ";
		std::getline(std::cin, _lastName);
	}
	while (_nickName.empty())
	{
		std::cout << MSG_ADD << "Nickname: ";
		std::getline(std::cin, _nickName);
	}
	while (_phoneNumber.empty() || !_isPhoneNumber(_phoneNumber))
	{
		std::cout << MSG_ADD << "Phone number: ";
		std::getline(std::cin, _phoneNumber);
	}
	while (_darkestSecret.empty())
	{
		std::cout << MSG_ADD << "Darkest secret: ";
		std::getline(std::cin, _darkestSecret);
	}
}

void	Contact::printListElement(int index)
{
	if (_firstName.empty() || _lastName.empty() || _nickName.empty())
		return ;
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << _resizeString(_firstName);
	std::cout << "|" << std::setw(10) << _resizeString(_lastName);
	std::cout << "|" << std::setw(10) << _resizeString(_nickName);
	std::cout << "|" << std::endl;
	std::cout << MSG_SEPARTOR << std::endl;
}

void	Contact::printContact(int index)
{
	if (_firstName.empty() || _lastName.empty() || _nickName.empty() || _phoneNumber.empty() || _darkestSecret.empty())
		std::cout << MSG_ERROR << "This contact has not been added yet." << std::endl;
	else
	{
		std::cout << "Index : " << index << std::endl;
		std::cout << "First name: " << _firstName << std::endl;
		std::cout << "Last name: " << _lastName << std::endl;
		std::cout << "Nickname: " << _nickName << std::endl;
		std::cout << "Phone number: " << _phoneNumber << std::endl;
		std::cout << "Darkest secret: " << _darkestSecret << std::endl;
	}
}