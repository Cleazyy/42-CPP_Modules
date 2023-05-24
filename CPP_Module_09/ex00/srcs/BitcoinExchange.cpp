/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:40:03 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/24 16:08:11 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

BitcoinExchange::BitcoinExchange(void) : _databaseFile("data.csv")
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
	std::ifstream databaseFile(this->_databaseFile);
	if (!databaseFile.is_open()) {
		throw std::runtime_error("failed to open data.csv");
	}

	std::string line, date, value;
	while (std::getline(databaseFile, line))
	{
		std::stringstream ss(line);

		if (std::getline(ss, date, ',') && std::getline(ss, value)) {
			this->_database[date] = std::strtof(value.c_str(), NULL);
		}
	}

	databaseFile.close();
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

void BitcoinExchange::printDatabase(void) const
{
    std::map<std::string, float>::const_iterator iter;

    for (iter = _database.begin(); iter != _database.end(); ++iter) {
        std::cout << "Date: " << iter->first << ", Value: " << iter->second << std::endl;
    }
}