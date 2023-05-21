/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:43:37 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/21 13:02:29 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> numbers;

	numbers.push_back(42);
	numbers.push_back(1337);
	numbers.push_back(19);
	numbers.push_back(21);

	try {
		std::vector<int>::iterator res = easyfind(numbers, 42);
		std::cout << *res << " found at index " << std::distance(numbers.begin(), res) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator res = easyfind(numbers, 1337);
		std::cout << *res << " found at index " << std::distance(numbers.begin(), res) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator res = easyfind(numbers, 19);
		std::cout << *res << " found at index " << std::distance(numbers.begin(), res) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator res = easyfind(numbers, 21);
		std::cout << *res << " found at index " << std::distance(numbers.begin(), res) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator res = easyfind(numbers, 95);
		std::cout << *res << " found at index " << std::distance(numbers.begin(), res) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}
