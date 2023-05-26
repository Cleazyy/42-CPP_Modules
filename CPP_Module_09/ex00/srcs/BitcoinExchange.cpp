/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:40:03 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/26 12:12:52 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

BitcoinExchange::BitcoinExchange(void)
{
	this->_parseDatabase();
	// std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
{
	// std::cout << "BitcoinExchange copy constructor called" << std::endl;
	*this = rhs;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	// std::cout << "BitcoinExchange copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_database = rhs._database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	// std::cout << "BitcoinExchange destructor called" << std::endl;
}

/* ************************************************************************** */
/*                          Private Member functions                          */
/* ************************************************************************** */

std::string BitcoinExchange::_trimWhiteSpaces(std::string &str)
{
	size_t first = str.find_first_not_of(" \t");
	if (first == std::string::npos) {
		return ("");
	}
	size_t last = str.find_last_not_of(" \t");
	return (str.substr(first, last - first + 1));
}

bool BitcoinExchange::_isValidDateFormat(std::string &str)
{
	if (str.length() != 10)
		return (false);

	if (str[4] != '-' || str[7] != '-')
		return (false);
	for (int i = 0; i < 4; i++) {
		if (!std::isdigit(str[i]))
			return (false);
	}
	if (!std::isdigit(str[5]) || !std::isdigit(str[6]))
		return (false);
	if (!std::isdigit(str[8]) || !std::isdigit(str[9]))
		return (false);

	int year = std::atoi(str.substr(0, 4).c_str());
	int month = std::atoi(str.substr(5, 2).c_str());
	int day = std::atoi(str.substr(8, 2).c_str());

	switch (month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (day < 1 || day > 31)
				return (false);
			break ;
		case 4: case 6: case 9: case 11:
			if (day < 1 || day > 30)
				return (false);
			break ;
		case 2:
			if (year % 4 == 0) {
				if (day < 1 || day > 29)
					return (false);
			} else {
				if (day < 1 || day > 28)
					return (false);
			}
			break ;
		default:
			return (false);
	}
	return (true);
}

bool BitcoinExchange::_isValidValueFormat(std::string &str)
{
	size_t i = 0;
	int points_nb = 0;

	if (str[0] == '+' || str[0] == '-')
		i++;
	while (i < str.length())
	{
		if (!std::isdigit(str[i]) && str[i] != '.')
			return (false);
		if (str[i] == '.')
			points_nb++;
		i++;
	}
	if (points_nb > 1)
		return (false);
	return (true);
}

void BitcoinExchange::_parseDatabase(void)
{
	std::ifstream databaseFile("data.csv");
	if (!databaseFile.is_open()) {
		throw std::runtime_error("failed to open data.csv");
	}

	std::string line, date, value;
	if (std::getline(databaseFile, line))
	{
		if (line.compare("date,exchange_rate")) {
			throw std::runtime_error("invalid data.csv file header"); 
		}
	}
	while (std::getline(databaseFile, line))
	{
		std::stringstream ss(line);

		if (std::getline(ss, date, ',') && std::getline(ss, value)) {
			if (this->_isValidDateFormat(date) == false) {
				throw std::runtime_error("data.csv contains invalid dates");
			}
			this->_database[date] = std::strtof(value.c_str(), NULL);
		}
		else {
			throw std::runtime_error("invalid data.csv file format");
		}
	}
	databaseFile.close();
}

std::string BitcoinExchange::_parseDate(std::string &str)
{
	std::string date = this->_trimWhiteSpaces(str);
	if (date.empty()) {
		std::cout << "Error: invalid date format => empty" << std::endl;
		return (date);
	}
	if (this->_isValidDateFormat(date) == false) {
		std::cout << "Error: invalid date format => " << date << std::endl;
		return ("");
	}
	return (date);
}

float BitcoinExchange::_parseValue(std::string &str)
{
	std::string nb = this->_trimWhiteSpaces(str);
	if (nb.empty()) {
		std::cout << "Error: invalid number format => empty" << std::endl;
		return (-1);
	}
	if (this->_isValidValueFormat(nb) == false) {
		std::cout << "Error: invalid number format => " << nb << std::endl;
		return (-1);
	}
	float value = std::strtof(nb.c_str(), NULL);
	if (errno == ERANGE) {
		std::cout << "Error: float overflow" << std::endl;
		return (-1);
	}
	if (value < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return (-1);
	}
	if (value > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return (-1);
	}
	return (value);
}

float BitcoinExchange::_getValue(std::string &date)
{
    std::map<std::string, float>::const_iterator it = this->_database.lower_bound(date);
	if (it == this->_database.begin()) {
		return (1);
	}
	else if (it == this->_database.end() || it->first != date) {
		--it;
    }
	return (it->second);
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

void BitcoinExchange::execute(std::string input)
{
	std::ifstream inputFile(input);
	if (!inputFile.is_open()) {
		throw std::runtime_error("failed to open input file");
	}

	float value, exchange_rate;
	std::string line, date, nb;
	if (std::getline(inputFile, line))
	{
		if (line.compare("date | value")) {
			throw std::runtime_error("invalid input file header"); 
		}
	}
	while (std::getline(inputFile, line))
	{
		std::stringstream ss(line);

		if (std::getline(ss, date, '|') && std::getline(ss, nb))
		{
			date = this->_parseDate(date);
			if (date.empty())
				continue ;
			value = this->_parseValue(nb);
			if (value < 0)
				continue ;
			exchange_rate = this->_getValue(date);
			std::cout << date << " => ";
			std::cout << value << " = ";
			std::cout << value * exchange_rate << std::endl;
		}
		else {
			std::cout << "Error: bad input => " << date << std::endl;
		}
	}
	inputFile.close();
}
