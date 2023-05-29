/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:49:56 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/29 09:41:04 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point	a(0, 0);
	Point	b(10, 30);
	Point	c(20, 0);

	/* Inside */
	std::cout << "[ Inside ]" << std::endl;
	std::cout << "Point(9, 15) --> " << bsp(a, b,  c, Point(9, 15)) << std::endl;
	std::cout << "Point(4, 1) --> " << bsp(a, b,  c, Point(4, 1)) << std::endl;
	std::cout << "Point(15, 14) --> " << bsp(a, b,  c, Point(15, 14)) << std::endl;
	std::cout << std::endl;

	/* Outside */
	std::cout << "[ Outside ]" << std::endl;
	std::cout << "Point(-5, 5) --> " << bsp(a, b,  c, Point(-5, 5)) << std::endl;
	std::cout << "Point(10, 35) --> " << bsp(a, b,  c, Point(10, 35)) << std::endl;
	std::cout << "Point(23, 5) --> " << bsp(a, b,  c, Point(23, 5)) << std::endl;
	std::cout << std::endl;

	/* Vertex points */
	std::cout << "[ Vertex ]" << std::endl;
	std::cout << "Point(0, 0) --> " << bsp(a, b, c, Point(0, 0)) << std::endl;
	std::cout << "Point(10, 30) --> " << bsp(a, b, c, Point(10, 30)) << std::endl;
	std::cout << "Point(20, 0) --> " << bsp(a, b, c, Point(20, 0)) << std::endl;
	std::cout << std::endl;

	/* Edge points */
	std::cout << "[ Edge ]" << std::endl;
	std::cout << "Point(1, 0) --> " << bsp(a, b, c, Point(1, 0)) << std::endl;
	std::cout << "Point(7, 0) --> " << bsp(a, b, c, Point(7, 0)) << std::endl;
	std::cout << "Point(14, 0) --> " << bsp(a, b, c, Point(14, 0)) << std::endl;

	return (0);
}
