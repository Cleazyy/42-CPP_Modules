/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:43:37 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/26 21:53:01 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Usage: ./RPN <expression>" << std::endl; 
		return (1);
	}

	try {
		RPN rpn;

		std::string expression = av[1];
		int result = rpn.calculation(expression);
		std::cout << result << std::endl;		
	}
	catch (std::exception &e){
		std::cout << "Error: " << e.what() << "." << std::endl; 
	}


	return (0);
}
