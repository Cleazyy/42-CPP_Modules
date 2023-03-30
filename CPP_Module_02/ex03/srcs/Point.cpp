/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 07:38:15 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/30 19:19:28 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

Point::Point(void) : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& rhs) : _x(rhs._x), _y(rhs._y) {}

Point&	Point::operator=(const Point& rhs)
{
	if (this != &rhs)
		const_cast<Fixed&>(this->_x) = rhs.getX();
		const_cast<Fixed&>(this->_y) = rhs.getY();
	return (*this);
}

Point::~Point(void) {}

/* ************************************************************************** */
/*                              Member functions                              */
/* ************************************************************************** */

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}