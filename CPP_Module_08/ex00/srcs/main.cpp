/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:43:37 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/21 13:11:07 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void	execute(int value)
{
	std::vector<int> numbers;
	numbers.push_back(42);
	numbers.push_back(1337);
	numbers.push_back(19);
	numbers.push_back(21);

	try {
		std::vector<int>::iterator res = easyfind(numbers, value);
		std::cout << *res << " found at index " << std::distance(numbers.begin(), res) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

int	main(void)
{
	execute(42);
	execute(1337);
	execute(19);
	execute(21);
	execute(95);

	return (0);
}
