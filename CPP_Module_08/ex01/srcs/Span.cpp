/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:40:03 by fluchten          #+#    #+#             */
/*   Updated: 2023/06/30 08:25:22 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

Span::Span(void) : _N(0)
{
	// std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N) : _N(N)
{
	// std::cout << "Span constructor called" << std::endl;
}

Span::Span(const Span &rhs)
{
	// std::cout << "Span copy constructor called" << std::endl;
	*this = rhs;
}

Span &Span::operator=(const Span &rhs)
{
	// std::cout << "Span copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_N = rhs._N;
		this->_numbers = rhs._numbers;
	}
	return (*this);
}

Span::~Span(void)
{
	// std::cout << "Span destructor called" << std::endl;
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

const std::vector<int> &Span::getNumbers() const
{
	return (this->_numbers);
}

void Span::addNumber(int N)
{
	if (this->_numbers.size() >= this->_N)
		throw std::runtime_error("Span is full");

	this->_numbers.push_back(N);
}

void Span::addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	unsigned int rangeSize = std::distance(begin, end);
	if (this->_numbers.size() + rangeSize > this->_N)
		throw std::runtime_error("Span is full");

	this->_numbers.insert(this->_numbers.end(), begin, end);
}

unsigned int Span::shortestSpan(void) const
{
	if (this->_numbers.size() <= 1)
		throw std::runtime_error("Cannot find shortest span");

	std::vector<int> sortedNumbers(this->_numbers);
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int shortest = sortedNumbers[1] - sortedNumbers[0];
	for (std::vector<int>::size_type i = 2; i < sortedNumbers.size(); i++) {
		int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < shortest) {
			shortest = span;
		}
	}

	return (shortest);
}

unsigned int Span::longestSpan(void) const
{
	if (this->_numbers.size() <= 1)
		throw std::runtime_error("Cannot find longest span");

	int longest = 0;
	for (std::vector<int>::size_type i = 1; i < this->_numbers.size(); i++) {
		int span = std::abs(this->_numbers[i] - this->_numbers[i - 1]);
		if (span > longest) {
			longest = span;
		}
	}

	return (longest);
}

/* ************************************************************************** */
/*                             Operators Overloads                            */
/* ************************************************************************** */

std::ostream &operator<<(std::ostream &o, const Span &rhs)
{
	const std::vector<int> &numbers = rhs.getNumbers();
    o << "Span = {";
    for (unsigned int i = 0; i < numbers.size(); ++i) {
        o << numbers[i];
        if (i != numbers.size() - 1) {
            o << ", ";
        }
    }
	o << "}";
	return (o);
}
