/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:01:28 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/10 18:47:27 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

Converter::Converter(void) : _nb("0")
{
	std::cout << "Converter default constructor called" << std::endl;
}

Converter::Converter(const std::string nb) : _nb(nb)
{
	std::cout << "Converter constructor called" << std::endl;
}

Converter::Converter(const Converter& rhs) : _nb(rhs._nb)
{
	std::cout << "Converter copy constructor called" << std::endl;
	*this = rhs;
}

Converter&	Converter::operator=(const Converter& rhs)
{
	std::cout << "Converter copy assignment operator called" << std::endl;
	(void) rhs;
	return (*this);
}

Converter::~Converter(void)
{
	std::cout << "Converter destructor called" << std::endl;
}

/* ************************************************************************** */
/*                          Private Member functions                          */
/* ************************************************************************** */

bool	Converter::_isChar(void)
{
	return (this->_nb.length() == 1 && !isdigit(this->_nb[0]));
}

void	Converter::_displayChar(void)
{
	std::cout << "char: ";
	std::cout << this->_nb[0];
	std::cout << std::endl;
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

void	Converter::execute(void)
{
	if (this->_isChar())
	{
		this->_displayChar();
	}
}

/* ************************************************************************** */
/*                            Exceptions functions                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                             Operators Overloads                            */
/* ************************************************************************** */

// std::ostream&	operator<<(std::ostream& o, const Bureaucrat& rhs)
// {
// 	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
// 	return (o);
// }
