/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:43:37 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/28 11:34:41 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Usage: ./btc <file>" << std::endl; 
		return (1);
	}

	try {
		BitcoinExchange btc;

		std::string input = av[1];
		btc.executeFile(input);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << "." << std::endl;
	}

	return (0);
}
