/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:40:03 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/27 19:33:33 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

RPN::RPN(void)
{
	// std::cout << "RPN default constructor called" << std::endl;
}

RPN::RPN(const RPN &rhs)
{
	// std::cout << "RPN copy constructor called" << std::endl;
	*this = rhs;
}

RPN &RPN::operator=(const RPN &rhs)
{
	// std::cout << "RPN copy assignment operator called" << std::endl;
	(void) rhs;
	return (*this);
}

RPN::~RPN(void)
{
	// std::cout << "RPN destructor called" << std::endl;
}

/* ************************************************************************** */
/*                          Private Member functions                          */
/* ************************************************************************** */

bool RPN::_isNumber(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i])) {
			return (false);
		}
	}
	return (true);
}

bool RPN::_isOperator(const std::string &str)
{
	return (str == "+" || str == "-" || str == "*" || str == "/");
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

int RPN::calculation(const std::string &expression)
{
	std::stack<int> stack;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (this->_isNumber(token)) {
			int number = std::atoi(token.c_str());
			if (number >= 10) {
				throw (std::runtime_error("invalid expression"));
			}
			stack.push(number);
		}
		else if (this->_isOperator(token)) {
			if (stack.size() < 2) {
				throw (std::runtime_error("invalid expression"));
			}

			int operand2 = stack.top();
			stack.pop();
			int operand1 = stack.top();
			stack.pop();

			int result;
			if (token == "+")
				result = operand1 + operand2;
			else if (token == "-")
				result = operand1 - operand2;
			else if (token == "*")
				result = operand1 * operand2;
			else if (token == "/") {
				if (operand2 == 0) {
					throw (std::runtime_error("division by zero"));
				}
				result = operand1 / operand2;
			}

			stack.push(result);
		}
		else {
			throw (std::runtime_error("invalid expression"));
		}
	}

	if (stack.size() != 1) {
		throw (std::runtime_error("invalid expression"));
	}

	return (stack.top());
}
