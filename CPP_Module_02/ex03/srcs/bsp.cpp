/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 07:43:45 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/30 17:51:52 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	abs(Fixed x)
{
	return (x < 0 ? x * -1 : x);
}

Fixed	area(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3)
{
	return (abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	x1 = a.getX();
	Fixed	y1 = a.getY();
	Fixed	x2 = b.getX();
	Fixed	y2 = b.getY();
	Fixed	x3 = c.getX();
	Fixed	y3 = c.getY();
	Fixed	x = point.getX();
	Fixed	y = point.getY();
	if ((x == x1 && y == y1) || (x == x2 && y == y2) || (x == x3 && y == y3))
		return (false);

	Fixed	ABC = area(x1, y1, x2, y2, x3, y3);
	Fixed	PBC = area(x, y, x2, y2, x3, y3);
	Fixed	PAC = area(x1, y1, x, y, x3, y3);
	Fixed	PAB = area(x1, y1, x2, y2, x, y);
	if (PBC == 0 || PAC == 0 || PAB == 0)
        return (false);

	return (ABC == PBC + PAC + PAB);
}