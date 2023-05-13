/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:01:28 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/13 16:30:59 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

Converter::Converter(void) : _nb("0")
{
	// std::cout << "Converter default constructor called" << std::endl;
}

Converter::Converter(const std::string nb) : _nb(nb)
{
	// std::cout << "Converter constructor called" << std::endl;
	if (this->_isChar())
		this->_type = CHAR;
	else if (this->_isInt())
		this->_type = INT;
	else if (this->_isFloat())
		this->_type = FLOAT;
	else if (this->_isDouble())
		this->_type = DOUBLE;
	else
		this->_type = INVALID;
}

Converter::Converter(const Converter& rhs) : _nb(rhs._nb)
{
	// std::cout << "Converter copy constructor called" << std::endl;
	*this = rhs;
}

Converter&	Converter::operator=(const Converter& rhs)
{
	// std::cout << "Converter copy assignment operator called" << std::endl;
	(void) rhs;
	return (*this);
}

Converter::~Converter(void)
{
	// std::cout << "Converter destructor called" << std::endl;
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
	float	resFloat = static_cast<float>(resChar);
	double	resDouble = static_cast<double>(resChar);

	this->_display(resChar, resInt, resFloat, resDouble);
}

void	Converter::_convertInt(void)
{
	int		resInt = std::atoi(this->_nb.c_str());

	char 	resChar = static_cast<char>(resInt);
	float	resFloat = static_cast<float>(resInt);
	double	resDouble = static_cast<double>(resInt);

	this->_display(resChar, resInt, resFloat, resDouble);
}

void	Converter::_convertFloat(void)
{
	float	resFloat = std::strtof(this->_nb.c_str(), NULL);
	if (errno == ERANGE)
		throw Converter::OverflowException();

	char 	resChar = static_cast<char>(resFloat);
	int		resInt = static_cast<int>(resFloat);
	double	resDouble = static_cast<double>(resFloat);

	this->_display(resChar, resInt, resFloat, resDouble);
}

void	Converter::_convertDouble(void)
{
	double	resDouble = std::strtod(this->_nb.c_str(), NULL);
	if (errno == ERANGE)
		throw Converter::OverflowException();

	char 	resChar = static_cast<char>(resDouble);
	int		resInt = static_cast<int>(resDouble);
	float	resFloat = static_cast<float>(resDouble);

	this->_display(resChar, resInt, resFloat, resDouble);
}

void	Converter::_displayChar(char resChar)
{
	if (isprint(resChar))
		std::cout << "char: '" << resChar << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
}

void	Converter::_displayInt(int resInt)
{
	std::cout << "int: " << resInt << std::endl;
}

void	Converter::_displayFloat(float resFloat)
{
	std::cout << "float: " << resFloat << std::endl;
}

void	Converter::_displayDouble(double resDouble)
{
	std::cout << "double: " << resDouble << std::endl;
}

void	Converter::_display(char resChar, int resInt, float resFloat, double resDouble)
{
	this->_displayChar(resChar);
	this->_displayInt(resInt);
	this->_displayFloat(resFloat);
	this->_displayDouble(resDouble);
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

void	Converter::execute(void)
{
	switch (this->_type)
	{
		case CHAR:
			this->_convertChar();
			break;
		case INT:
			this->_convertInt();
			break;
		case FLOAT:
			this->_convertFloat();
			break;
		case DOUBLE:
			this->_convertDouble();
			break;
		default:
			throw Converter::InvalidTypeException();
	}
}

/* ************************************************************************** */
/*                            Exceptions functions                            */
/* ************************************************************************** */

const char	*Converter::InvalidTypeException::what() const throw()
{
	return ("Invalid number: unknown type!");
}

const char	*Converter::OverflowException::what() const throw()
{
	return ("Invalid number: overflow!");
}

/* ************************************************************************** */
/*                             Operators Overloads                            */
/* ************************************************************************** */

// std::ostream&	operator<<(std::ostream& o, const Bureaucrat& rhs)
// {
// 	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
// 	return (o);
// }
