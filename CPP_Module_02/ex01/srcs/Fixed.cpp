/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:49:54 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/28 21:09:35 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructor */
Fixed::Fixed(void) : _fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/* Int constructor */
Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = (nb << Fixed::_bits);
}

/* Float constructor */
Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = roundf(nb * (1 << Fixed::_bits));
}

/* Copy constructor */
Fixed::Fixed(const Fixed& rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

/* Assignment operator */
Fixed&	Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixed = rhs.getRawBits();
	return (*this);
}

/* Destructor */
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixed / (1 << Fixed::_bits));
}

int		Fixed::toInt(void) const
{
	return (this->_fixed >> Fixed::_bits);
}

std::ostream&	operator<<(std::ostream& o, const Fixed& rhs)
{
	o << rhs.toFloat();
	return (o);
}