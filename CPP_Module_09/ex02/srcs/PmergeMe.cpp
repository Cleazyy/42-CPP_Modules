/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:40:03 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/27 19:33:24 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

PmergeMe::PmergeMe(void)
{
	// std::cout << "PmergeMe default constructor called" << std::endl;
}

PmergeMe::PmergeMe(int ac, char **av)
{
	// std::cout << "PmergeMe constructor called" << std::endl;
	this->_parseInput(ac, av);
}

PmergeMe::PmergeMe(const PmergeMe &rhs)
{
	// std::cout << "PmergeMe copy constructor called" << std::endl;
	*this = rhs;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	// std::cout << "PmergeMe copy assignment operator called" << std::endl;
	(void) rhs;
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	// std::cout << "PmergeMe destructor called" << std::endl;
}

/* ************************************************************************** */
/*                          Private Member functions                          */
/* ************************************************************************** */

bool PmergeMe::_isInt(char *str)
{
	int i = 0;

	if (str[0] == '+')
		i++;
	while (str[i])
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

void PmergeMe::_parseInput(int ac, char **av)
{
	for (int i = 1; i < ac; i++) {
		if (this->_isInt(av[i]) == false) {
			throw (std::runtime_error("invalid input"));
		}
		std::istringstream iss(av[i]);
		int number;
		iss >> number;
		if (iss.fail()) {
			throw (std::runtime_error("invalid input"));
		}
		this->_vector.push_back(number);
		this->_deque.push_back(number);
	}
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */
