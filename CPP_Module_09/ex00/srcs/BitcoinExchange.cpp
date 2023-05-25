/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:40:03 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/25 22:03:58 by fluchten         ###   ########.fr       */
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

std::string BitcoinExchange::_trimWhiteSpaces(std::string &str)
{
	size_t first = str.find_first_not_of(" \t");
	if (first == std::string::npos) {
		return ("");
	}
	size_t last = str.find_last_not_of(" \t");
	return (str.substr(first, last - first + 1));
}

bool BitcoinExchange::_isValidDateFormat(const std::string &date)
{
	if (date.length() != 10)
		return (false);

	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; i < 4; i++) {
		if (!std::isdigit(date[i]))
			return (false);
	}
	if (!std::isdigit(date[5]) || !std::isdigit(date[6]))
		return (false);
	if (!std::isdigit(date[8]) || !std::isdigit(date[9]))
		return (false);

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

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

std::string BitcoinExchange::_parseDate(std::string &str)
{
	std::string date = this->_trimWhiteSpaces(str);
	if (date.empty())
	{
		std::cout << "Error: invalid date format => empty" << std::endl;
		return (date);
	}
	if (this->_isValidDateFormat(date) == false) {
		std::cout << "Error: invalid date format => " << str << std::endl;
		return ("");
	}
	return (date);
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

	std::string line, date, value;
	if (std::getline(inputFile, line))
	{
		if (line.compare("date | value")) {
			throw std::runtime_error("invalid input file header"); 
		}
	}
	while (std::getline(inputFile, line))
	{
		std::stringstream ss(line);

		if (std::getline(ss, date, '|') && std::getline(ss, value))
		{
			date = this->_parseDate(date);
			if (!date.empty()) {
				std::cout << date << " => ";
				std::cout << value << std::endl;
			}
		}
	}

	inputFile.close();
}

void BitcoinExchange::printDatabase(void) const
{
    std::map<std::string, float>::const_iterator iter;

    for (iter = _database.begin(); iter != _database.end(); ++iter) {
        std::cout << "Date: " << iter->first << ", Value: " << iter->second << std::endl;
    }
}