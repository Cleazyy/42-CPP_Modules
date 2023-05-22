/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:43:37 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/22 20:42:47 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	try {
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp << std::endl;
		std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span = " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Span sp = Span(4);

		sp.addNumber(42);
		sp.addNumber(1337);
		sp.addNumber(19);
		sp.addNumber(21);

		std::cout << sp << std::endl;
		std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span = " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Span sp(10000);

		std::vector<int> randomNumbers;
		std::srand(std::time(NULL));
		for (int i = 0; i < 10000; i++)	{
			randomNumbers.push_back(std::rand());
		}
		sp.addNumbers(randomNumbers.begin(), randomNumbers.end());
		// std::cout << sp << std::endl;
		std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span = " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}
