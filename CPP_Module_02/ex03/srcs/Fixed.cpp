/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:49:54 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/30 19:35:57 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

Fixed::Fixed(void) : _fixed(0) {}

Fixed::Fixed(const int nb)
{
	this->_fixed = (nb << Fixed::_bits); // (nb * 2^bits)
}

Fixed::Fixed(const float nb)
{
	this->_fixed = roundf(nb * (1 << Fixed::_bits));
}

Fixed::Fixed(const Fixed& rhs)
{
	*this = rhs;
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	if (this != &rhs)
		this->_fixed = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed(void) {}

/* ************************************************************************** */
/*                            Comparison operators                            */
/* ************************************************************************** */

bool	Fixed::operator>(const Fixed& rhs) const
{
	return (this->_fixed > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed& rhs) const
{
	return (this->_fixed < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed& rhs) const
{
	return (this->_fixed >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return (this->_fixed <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return (this->_fixed == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed& rhs) const
{
	return (this->_fixed != rhs.getRawBits());
}

/* ************************************************************************** */
/*                            Arithmetic operators                            */
/* ************************************************************************** */

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	return (this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	return (this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	return (this->toFloat() / rhs.toFloat());
}

/* ************************************************************************** */
/*                     Increment and decrement operators                      */
/* ************************************************************************** */

Fixed&	Fixed::operator++(void)
{
	++this->_fixed;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	operator++();
	return (tmp);
}

Fixed&	Fixed::operator--(void)
{
	--this->_fixed;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	operator--();
	return (tmp);
}

/* ************************************************************************** */
/*                              Member functions                              */
/* ************************************************************************** */

int	Fixed::getRawBits(void) const
{
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

int	Fixed::toInt(void) const
{
	return (this->_fixed >> Fixed::_bits);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

/* ************************************************************************** */
/*                                   Other                                    */
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& o, const Fixed& rhs)
{
	o << rhs.toFloat();
	return (o);
}