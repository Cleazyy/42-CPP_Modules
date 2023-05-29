/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:15:56 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/29 08:59:03 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */

Contact::Contact(void) {}

Contact::~Contact(void) {}

/* ************************************************************************** */
/*                          Private Member functions                          */
/* ************************************************************************** */

void Contact::_init(void)
{
	this->_firstName = "";
	this->_lastName = "";
	this->_nickName = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
}

bool Contact::_isPhoneNumber(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i])) {
			return (false);
		}
	}
	return (true);
}

bool Contact::_isExist(void)
{
	if (this->_firstName.empty() || this->_lastName.empty() || this->_nickName.empty() || this->_phoneNumber.empty() || this->_darkestSecret.empty()) {
		return (false);
	}
	return (true);
}

std::string Contact::_resizeString(const std::string &str)
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

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

void Contact::getSettings(void)
{
	this->_init();
	while (this->_firstName.empty())
	{
		std::cout << MSG_ADD << "First name: ";
		std::getline(std::cin, this->_firstName);
	}
	while (this->_lastName.empty())
	{
		std::cout << MSG_ADD << "Last name: ";
		std::getline(std::cin, this->_lastName);
	}
	while (this->_nickName.empty())
	{
		std::cout << MSG_ADD << "Nickname: ";
		std::getline(std::cin, this->_nickName);
	}
	while (this->_phoneNumber.empty() || this->_isPhoneNumber(this->_phoneNumber) == false)
	{
		std::cout << MSG_ADD << "Phone number: ";
		std::getline(std::cin, this->_phoneNumber);
	}
	while (this->_darkestSecret.empty())
	{
		std::cout << MSG_ADD << "Darkest secret: ";
		std::getline(std::cin, this->_darkestSecret);
	}
}

void Contact::printElementList(int index)
{
	if (this->_isExist() == false)
		return ;
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << this->_resizeString(this->_firstName);
	std::cout << "|" << std::setw(10) << this->_resizeString(this->_lastName);
	std::cout << "|" << std::setw(10) << this->_resizeString(this->_nickName);
	std::cout << "|" << std::endl;
	std::cout << MSG_SEPARTOR << std::endl;
}

void Contact::printContact(int index)
{
	if (this->_isExist() == false)
		std::cout << MSG_ERROR << "This contact has not been added yet." << std::endl;
	else
	{
		std::cout << "Index : " << index << std::endl;
		std::cout << "First name: " << this->_firstName << std::endl;
		std::cout << "Last name: " << this->_lastName << std::endl;
		std::cout << "Nickname: " << this->_nickName << std::endl;
		std::cout << "Phone number: " << this->_phoneNumber << std::endl;
		std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
	}
}
