/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:40:03 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/26 18:34:09 by fluchten         ###   ########.fr       */
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
	// if (this != &rhs)
	// 	this->_database = rhs._database;
	return (*this);
}

RPN::~RPN(void)
{
	// std::cout << "RPN destructor called" << std::endl;
}

/* ************************************************************************** */
/*                          Private Member functions                          */
/* ************************************************************************** */

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */
