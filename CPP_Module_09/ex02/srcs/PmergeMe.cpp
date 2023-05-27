/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:40:03 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/27 21:20:59 by fluchten         ###   ########.fr       */
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
	if (this != &rhs) {
		this->_vector = rhs._vector;
		this->_deque = rhs._deque;
	}
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

void PmergeMe::_mergeVector(int left, int middle, int right)
{
	int size_left = middle - left + 1;
	int size_right = right - middle;

	std::vector<int> left_subvector(size_left);
	std::vector<int> right_subvector(size_right);

	for (int i = 0; i < size_left; i++)
		left_subvector[i] = this->_vector[left + i];

	for (int j = 0; j < size_right; j++)
		right_subvector[j] = this->_vector[middle + 1 + j];

	int i = 0;
	int j = 0;
	int k = left;

	while (i < size_left && j < size_right) {
		if (left_subvector[i] <= right_subvector[j]) {
			this->_vector[k] = left_subvector[i];
			i++;
		} else {
			this->_vector[k] = right_subvector[j];
			j++;
		}
		k++;
	}

	while (i < size_left) {
		this->_vector[k] = left_subvector[i];
		++i;
		++k;
	}

	while (j < size_right) {
		this->_vector[k] = right_subvector[j];
		++j;
		++k;
	}
}

void PmergeMe::_mergeSortVector(int left, int right)
{
	if (left < right) {
		int middle = left + (right - left) / 2;

		this->_mergeSortVector(left, middle);
		this->_mergeSortVector(middle + 1, right);
		this->_mergeVector(left, middle, right);
	}
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

void PmergeMe::sortVector(void)
{
	int left = 0;
	int right = this->_vector.size() - 1;

	this->_mergeSortVector(left, right);
	std::cout << "After:  ";
	for (std::vector<int>::const_iterator it = this->_vector.begin(); it != this->_vector.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::sortDeque(void)
{
	
}