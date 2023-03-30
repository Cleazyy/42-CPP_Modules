/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:49:56 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/30 12:57:12 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static Fixed	abs(Fixed x)
{
	return (x < 0 ? x * -1 : x);
}

static Fixed	area( Point const a, Point const b, Point const c )
{
	return (((a.getX() * (b.getY() - c.getY())) + (b.getX() * (c.getY() - a.getY())) + (c.getX() * (a.getY() - b.getY()))) / 2);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	abcArea = abs(area(a, b, c));
	Fixed	pabArea = abs(area(point, a, b));
	Fixed	pbcArea = abs(area(point, b, c));
	Fixed	pcaArea = abs(area(point, c, a));

	return  (abcArea == pabArea + pbcArea + pcaArea);
}

int	main(void)
{
	if (bsp(Point(0, 0), Point(10, 30), Point(20, 0), Point(30, 15)) == true)
		std::cout << "Point is in the triangle" << std::endl;
	else
		std::cout << "Point is not in the triangle" << std::endl;
	return 0;
}