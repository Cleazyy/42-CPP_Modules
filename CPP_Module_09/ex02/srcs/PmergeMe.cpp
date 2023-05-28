/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:40:03 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/28 11:25:03 by fluchten         ###   ########.fr       */
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

void PmergeMe::_insertVector(int left, int right)
{
	for (int i = left + 1; i <= right; i++) {
		int key = this->_vector[i];
		int j = i - 1;

		while (j >= left && this->_vector[j] > key) {
			this->_vector[j + 1] = this->_vector[j];
			j--;
		}
		this->_vector[j + 1] = key;
	}
}

void PmergeMe::_mergeVector(int left, int middle, int right)
{
	int size_left = middle - left + 1;
	int size_right = right - middle;

    int *left_subarray = new int[size_left];
    int *right_subarray = new int[size_right];

	for (int i = 0; i < size_left; i++)
		left_subarray[i] = this->_vector[left + i];

	for (int j = 0; j < size_right; j++)
		right_subarray[j] = this->_vector[middle + 1 + j];

	int i = 0;
	int j = 0;
	int k = left;

	while (i < size_left && j < size_right) {
		if (left_subarray[i] <= right_subarray[j]) {
			this->_vector[k] = left_subarray[i];
			i++;
		} else {
			this->_vector[k] = right_subarray[j];
			j++;
		}
		k++;
	}

	while (i < size_left) {
		this->_vector[k] = left_subarray[i];
		++i;
		++k;
	}

	while (j < size_right) {
		this->_vector[k] = right_subarray[j];
		++j;
		++k;
	}

	delete [] left_subarray;
	delete [] right_subarray;
}

void PmergeMe::_mergeSortVector(int left, int right)
{
	if (left < right) {
		if (right - left + 1 <= 4) {
			this->_insertVector(left, right);
		}
		else {
			int middle = left + (right - left) / 2;

			this->_mergeSortVector(left, middle);
			this->_mergeSortVector(middle + 1, right);
			this->_mergeVector(left, middle, right);
		}
	}
}

void PmergeMe::_insertDeque(int left, int right)
{
	for (int i = left + 1; i <= right; i++) {
		int key = this->_deque[i];
		int j = i - 1;

		while (j >= left && this->_deque[j] > key) {
			this->_deque[j + 1] = this->_deque[j];
			j--;
		}
		this->_deque[j + 1] = key;
	}
}

void PmergeMe::_mergeDeque(int left, int middle, int right)
{
	int size_left = middle - left + 1;
	int size_right = right - middle;

    int *left_subarray = new int[size_left];
    int *right_subarray = new int[size_right];

	for (int i = 0; i < size_left; i++)
		left_subarray[i] = this->_deque[left + i];

	for (int j = 0; j < size_right; j++)
		right_subarray[j] = this->_deque[middle + 1 + j];

	int i = 0;
	int j = 0;
	int k = left;

	while (i < size_left && j < size_right) {
		if (left_subarray[i] <= right_subarray[j]) {
			this->_deque[k] = left_subarray[i];
			i++;
		} else {
			this->_deque[k] = right_subarray[j];
			j++;
		}
		k++;
	}

	while (i < size_left) {
		this->_deque[k] = left_subarray[i];
		++i;
		++k;
	}

	while (j < size_right) {
		this->_deque[k] = right_subarray[j];
		++j;
		++k;
	}

	delete [] left_subarray;
	delete [] right_subarray;
}

void PmergeMe::_mergeSortDeque(int left, int right)
{
	if (left < right) {
		if (right - left + 1 <= 4) {
			this->_insertDeque(left, right);
		}
		else {
			int middle = left + (right - left) / 2;

			this->_mergeSortDeque(left, middle);
			this->_mergeSortDeque(middle + 1, right);
			this->_mergeDeque(left, middle, right);
		}
	}
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

void PmergeMe::sortVector(void)
{
	int left = 0;
	int right = this->_vector.size() - 1;

	std::clock_t start_time = std::clock();

	this->_mergeSortVector(left, right);

	std::clock_t end_time = std::clock();
    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "After:  ";
	for (std::vector<int>::const_iterator it = this->_vector.begin(); it != this->_vector.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector: " << elapsed_time << " us" << std::endl;
}

void PmergeMe::sortDeque(void)
{
	int left = 0;
	int right = this->_deque.size() - 1;

	std::clock_t start_time = std::clock();

	this->_mergeSortDeque(left, right);

	std::clock_t end_time = std::clock();
    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque: " << elapsed_time << " us" << std::endl;
}
