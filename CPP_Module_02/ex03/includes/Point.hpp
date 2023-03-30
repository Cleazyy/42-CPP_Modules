/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 07:38:19 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/30 08:48:55 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		/* Canonical form */
		Point(void);
		Point(const float x, const float y);
		Point(const Point& rhs);
		Point& operator=(const Point& rhs);
		~Point(void);

		/* Member functions */
		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

#endif