/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:01:28 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/14 09:48:01 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

Converter::Converter(void)
{
	std::cout << "Converter default constructor called" << std::endl;
}

Converter::Converter(const Converter &rhs)
{
	std::cout << "Converter copy constructor called" << std::endl;
	*this = rhs;
}

Converter	&Converter::operator=(const Converter &rhs)
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

int		Converter::strToInt(std::string str, int *overflow)
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

e_type	Converter::getType(std::string str)
{
	e_type type;

	if (isChar(str))
		type = CHAR;
	else if (isInt(str))
		type = INT;
	else if (isFloat(str))
		type = FLOAT;
	else if (isDouble(str))
		type = DOUBLE;
	else if (isSpecial(str))
		type = SPECIAL;
	else
		type = INVALID;
	return (type);
}

bool	Converter::isChar(std::string str)
{
	return (str.size() == 1 && !std::isdigit(str[0]));
}

bool	Converter::isInt(std::string str)
{
	int i = 0;

	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	Converter::isFloat(std::string str)
{
	size_t	i = 0;
	int		points_nb = 0;

	if (str[0] == '+' || str[0] == '-')
		i++;
	while (i < str.length() - 1)
	{
		if (!std::isdigit(str[i]) && str[i] != '.')
			return (false);
		if (str[i] == '.')
			points_nb++;
		i++;
	}
	if (points_nb != 1 || str[str.length() - 1] != 'f')
		return (false);
	return (true);
}

bool	Converter::isDouble(std::string str)
{
	size_t	i = 0;
	int		points_nb = 0;

	if (str[0] == '+' || str[0] == '-')
		i++;
	while (i < str.length())
	{
		if (!std::isdigit(str[i]) && str[i] != '.')
			return (false);
		if (str[i] == '.')
			points_nb++;
		i++;
	}
	if (points_nb != 1)
		return (false);
	return (true);
}

bool	Converter::isSpecial(std::string str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (true);
	else if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	return (false);
}

void	Converter::convertChar(std::string str)
{
	char c = str[0];

	displayChar(c);
	displayInt(static_cast<int>(c));
	displayFloat(static_cast<float>(c));
	displayDouble(static_cast<double>(c));
}

void	Converter::convertInt(std::string str)
{
	int	overflow = 0;
	int	nb = strToInt(str, &overflow);
	if (overflow != 0)
	{
		std::cout << "Invalid number: int overflow" << std::endl;
		return ;
	}
	displayChar(static_cast<char>(nb));
	displayInt(nb);
	displayFloat(static_cast<float>(nb));
	displayDouble(static_cast<double>(nb));
}

void	Converter::convertFloat(std::string str)
{
	float nb = std::strtof(str.c_str(), NULL);
	if (errno == ERANGE)
	{
		std::cout << "Invalid number: float overflow" << std::endl;
		return ;
	}
	displayChar(static_cast<char>(nb));
	displayInt(static_cast<int>(nb));
	displayFloat(nb);
	displayDouble(static_cast<double>(nb));
}

void	Converter::convertDouble(std::string str)
{
	double nb = std::strtod(str.c_str(), NULL);
	if (errno == ERANGE)
	{
		std::cout << "Invalid number: double overflow" << std::endl;
		return ;
	}
	displayChar(static_cast<char>(nb));
	displayInt(static_cast<int>(nb));
	displayFloat(static_cast<float>(nb));
	displayDouble(nb);
}

void	Converter::displayChar(char c)
{
	std::cout << "char: ";
	if (std::isprint(c)) 
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void	Converter::displayInt(int nb)
{
	std::cout << "int: ";
	std::cout << nb << std::endl;
}

void	Converter::displayFloat(float nb)
{
	std::cout << "float: ";
	if (nb == static_cast<int>(nb))
		std::cout << nb << ".0f" << std::endl;
	else
		 std::cout << nb << "f" << std::endl;
}

void	Converter::displayDouble(double nb)
{
	std::cout << "double: ";;
	if (nb == static_cast<int>(nb))
		std::cout << nb << ".0" << std::endl;
	else
		 std::cout << nb << std::endl;
}

void	Converter::displaySpecial(std::string str)
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	if (str == "-inff" || str == "-inf")
	{
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
	}
	else if (str == "+inff" || str == "+inf")
	{
		std::cout << "float: " << "+inff" << std::endl;
		std::cout << "double: " << "+inf" << std::endl;
	}
	else if (str == "nanf" || str == "nan")
	{
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

void	Converter::execute(std::string str)
{
	e_type type = getType(str);

	switch (type)
	{
		case CHAR:
			convertChar(str);
			break;
		case INT:
			convertInt(str);
			break;
		case FLOAT:
			convertFloat(str);
			break;
		case DOUBLE:
			convertDouble(str);
			break;
		case SPECIAL:
			displaySpecial(str);
			break;
		default:
			std::cout << "Invalid number: unknown type!" << std::endl;
			break;
	}
}
