/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:23:26 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/08 11:57:44 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	/* TEST 1 */
	std::cout << "\033[1;34m" << "[ TEST 1 ]" << "\033[0m" << std::endl;
	try {
		Bureaucrat	bureaucrat("Bureaucrat", 42);
		Form		form("Contract", 42, 1);

		std::cout << std::endl;
		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	/* TEST 2 */
	std::cout << "\033[1;34m" << "[ TEST 2 ]" << "\033[0m" << std::endl;
	try {
		Bureaucrat	bureaucrat("Bureaucrat", 42);
		Form		form("Contract", 19, 1);

		std::cout << std::endl;
		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
