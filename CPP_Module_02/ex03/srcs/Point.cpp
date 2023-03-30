/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 07:38:15 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/30 08:49:36 by fluchten         ###   ########.fr       */
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
		// this->_x = rhs.getX();
		// this->_y = rhs.getY();
		(void) rhs;
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