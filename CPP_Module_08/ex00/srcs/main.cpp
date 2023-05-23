/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:43:37 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/23 07:28:28 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void	execute(std::vector<int> numbers, int value)
{
	try {
		std::vector<int>::const_iterator res = easyfind(numbers, value);
		std::cout << *res << " found at index " << std::distance(numbers.cbegin(), res) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

int	main(void)
{
	std::vector<int> numbers;

	numbers.push_back(42);
	numbers.push_back(1337);
	numbers.push_back(19);
	numbers.push_back(21);

	execute(numbers, 42);
	execute(numbers, 1337);
	execute(numbers, 19);
	execute(numbers, 21);
	execute(numbers, 95);

	return (0);
}
