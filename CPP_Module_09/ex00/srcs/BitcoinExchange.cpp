/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:40:03 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/23 19:33:25 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

BitcoinExchange::BitcoinExchange(void)
{
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
/*                          Public Member functions                           */
/* ************************************************************************** */
