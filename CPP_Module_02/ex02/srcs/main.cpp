/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:49:56 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/29 09:36:05 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static void	pdf_tests(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
}

int	main(void)
{
	/* PDF */
	std::cout << "[ PDF ]" << std::endl;
	pdf_tests();
	std::cout << std::endl;

	/* Constructors */
	Fixed a;
	Fixed b(10);
	Fixed c(42.42f);
	Fixed d(b);

	/* Comparison operators */
	std::cout << "[ Comparison operators ]" << std::endl;
	std::cout << (a < b) << std::endl;
	std::cout << (b > c) << std::endl;
	std::cout << (c >= d) << std::endl;
	std::cout << (d <= b) << std::endl;
	std::cout << (b == b) << std::endl;
	std::cout << (c != d) << std::endl;
	std::cout << std::endl;

	/* Arithmetic operators */
	std::cout << "[ Arithmetic operators ]" << std::endl;
	std::cout << (a + b) << std::endl;
	std::cout << (b - a) << std::endl;
	std::cout << (c * d) << std::endl;
	std::cout << (d / b) << std::endl;
	std::cout << std::endl;

	/* Increment and decrement operators */
	std::cout << "[ Increment and decrement operators ]" << std::endl;
	std::cout << (++a) << std::endl;
	std::cout << (b++) << std::endl;
	std::cout << (c--) << std::endl;
	std::cout << (--d) << std::endl;
	std::cout << std::endl;

	/* Convertions functions */
	std::cout << "[ Member functions ]" << std::endl;
	std::cout << a.toInt() << std::endl;
	std::cout << a.toFloat() << std::endl;
	std::cout << b.toInt() << std::endl;
	std::cout << b.toFloat() << std::endl;
	std::cout << c.toInt() << std::endl;
	std::cout << c.toFloat() << std::endl;
	std::cout << d.toInt() << std::endl;
	std::cout << d.toFloat() << std::endl;
	std::cout << std::endl;

	/* Min max functions */
	std::cout << "[ Min max functions ]" << std::endl;
	std::cout << Fixed::max(b, d) << std::endl;
	std::cout << Fixed::min(b, d) << std::endl;
}
