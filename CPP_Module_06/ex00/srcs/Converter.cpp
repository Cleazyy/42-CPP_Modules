/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:01:28 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/13 11:38:11 by fluchten         ###   ########.fr       */
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
	if (this->_isChar())
		this->_type = "char";
	else if (this->_isInt())
		this->_type = "int";
	else if (this->_isFloat())
		this->_type = "float";
	else if (this->_isDouble())
		this->_type = "double";
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

bool	Converter::_isInt(void)
{
	int i = 0;

	if (this->_nb[0] == '+' || this->_nb[0] == '-')
		i++;
	while (this->_nb[i])
	{
		if (!isdigit(this->_nb[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	Converter::_isFloat(void)
{
	size_t	i = 0;
	int		points_nb = 0;

	if (this->_nb[0] == '+' || this->_nb[0] == '-')
		i++;
	while (i < this->_nb.length() - 1)
	{
		if (!isdigit(this->_nb[i]) && this->_nb[i] != '.')
			return (false);
		if (this->_nb[i] == '.')
			points_nb++;
		i++;
	}
	if (points_nb != 1 || this->_nb[this->_nb.length() - 1] != 'f')
		return (false);
	return (true);
}

bool	Converter::_isDouble(void)
{
	size_t	i = 0;
	int		points_nb = 0;

	if (this->_nb[0] == '+' || this->_nb[0] == '-')
		i++;
	while (i < this->_nb.length())
	{
		if (!isdigit(this->_nb[i]) && this->_nb[i] != '.')
			return (false);
		if (this->_nb[i] == '.')
			points_nb++;
		i++;
	}
	if (points_nb != 1)
		return (false);
	return (true);
}

void	Converter::_convertChar(void)
{
	char 	resChar = this->_nb[0];
	int		resInt = static_cast<int>(resChar);
	this->_display(resChar);
}

void	Converter::_display(char resChar)
{
	std::cout << "char: '" << resChar << "'" << std::endl;
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

void	Converter::execute(void)
{
	if (this->_type == "char")
		this->_convertChar();
	else if (this->_type == "int")
		std::cout << "type = INT" << std::endl;
	else if (this->_type == "float")
		std::cout << "type = FLOAT" << std::endl;
	else if (this->_type == "double")
		std::cout << "type = DOUBLE" << std::endl;
	else
		std::cout << "type = INVALID" << std::endl;
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
