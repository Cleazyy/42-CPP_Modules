/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:01:28 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/13 20:48:17 by fluchten         ###   ########.fr       */
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
	else if (this->_isSpecial())
		this->_type = SPECIAL;
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

int		Converter::_strToInt(std::string str, int *overflow)
{
	long	res = 0;
	int		sign = 1;
	size_t	i = 0;

	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (i < str.size() && std::isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		if (sign * res < std::numeric_limits<int>::min())
			*overflow = 1;
		if (sign * res > std::numeric_limits<int>::max())
			*overflow = 1;
		i++;
	}
	return (sign * static_cast<int>(res));
}

bool	Converter::_isChar(void)
{
	return (this->_nb.size() == 1 && !std::isdigit(this->_nb[0]));
}

bool	Converter::_isInt(void)
{
	int i = 0;

	if (this->_nb[0] == '+' || this->_nb[0] == '-')
		i++;
	while (this->_nb[i])
	{
		if (!std::isdigit(this->_nb[i]))
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
		if (!std::isdigit(this->_nb[i]) && this->_nb[i] != '.')
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
		if (!std::isdigit(this->_nb[i]) && this->_nb[i] != '.')
			return (false);
		if (this->_nb[i] == '.')
			points_nb++;
		i++;
	}
	if (points_nb != 1)
		return (false);
	return (true);
}

bool	Converter::_isSpecial(void)
{
	if (this->_nb == "-inff" || this->_nb == "+inff" || this->_nb == "nanf")
		return (true);
	else if (this->_nb == "-inf" || this->_nb == "+inf" || this->_nb == "nan")
		return (true);
	return (false);
}

void	Converter::_convertChar(void)
{
	char c = this->_nb[0];

	this->_displayChar(c);
	this->_displayInt(static_cast<int>(c));
	this->_displayFloat(static_cast<float>(c));
	this->_displayDouble(static_cast<double>(c));
}

void	Converter::_convertInt(void)
{
	int	overflow = 0;
	int	nb = this->_strToInt(this->_nb, &overflow);
	if (overflow != 0)
	{
		std::cout << "Invalid number: int overflow" << std::endl;
		return ;
	}
	this->_displayChar(static_cast<int>(nb));
	this->_displayInt(nb);
	this->_displayFloat(static_cast<float>(nb));
	this->_displayDouble(static_cast<double>(nb));
}

void	Converter::_convertFloat(void)
{
	float nb = std::strtof(this->_nb.c_str(), NULL);
	if (errno == ERANGE)
	{
		std::cout << "Invalid number: float overflow" << std::endl;
		return ;
	}
	this->_displayChar(static_cast<char>(nb));
	this->_displayInt(static_cast<int>(nb));
	this->_displayFloat(nb);
	this->_displayDouble(static_cast<double>(nb));
}

void	Converter::_convertDouble(void)
{
	double nb = std::strtod(this->_nb.c_str(), NULL);
	if (errno == ERANGE)
	{
		std::cout << "Invalid number: double overflow" << std::endl;
		return ;
	}
	this->_displayChar(static_cast<char>(nb));
	this->_displayInt(static_cast<int>(nb));
	this->_displayFloat(static_cast<float>(nb));
	this->_displayDouble(nb);
}

void	Converter::_displayChar(char c)
{
	std::cout << "char: ";
	if (std::isprint(c)) 
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void	Converter::_displayInt(int nb)
{
	std::cout << "int: ";
	std::cout << nb << std::endl;
}

void	Converter::_displayFloat(float nb)
{
	std::cout << "float: ";
	if (nb == static_cast<int>(nb))
		std::cout << nb << ".0f" << std::endl;
	else
		 std::cout << nb << "f" << std::endl;
}

void	Converter::_displayDouble(double nb)
{
	std::cout << "double: ";;
	if (nb == static_cast<int>(nb))
		std::cout << nb << ".0" << std::endl;
	else
		 std::cout << nb << std::endl;
}

void	Converter::_displaySpecial(void)
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	if (this->_nb == "-inff" || this->_nb == "-inf")
	{
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
	}
	else if (this->_nb == "+inff" || this->_nb == "+inf")
	{
		std::cout << "float: " << "+inff" << std::endl;
		std::cout << "double: " << "+inf" << std::endl;
	}
	else if (this->_nb == "nanf" || this->_nb == "nan")
	{
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
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
		case SPECIAL:
			this->_displaySpecial();
			break;
		default:
			std::cout << "Invalid number: unknown type!" << std::endl;
			break;
	}
}
