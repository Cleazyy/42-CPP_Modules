/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:23:26 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/08 10:03:09 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	/* TEST 1 */
	std::cout << "\033[1;34m" << "[ TEST 1 ]" << "\033[0m" << std::endl;
	try {
		Bureaucrat	bureaucrat("Bureaucrat", 42);

		std::cout << std::endl;
		std::cout << bureaucrat << std::endl;
		for (int i = 0; i < 24; i++)
			bureaucrat.promoteGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.demoteGrade();
		std::cout << bureaucrat << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	/* TEST 2 */
	std::cout << "\033[1;34m" << "[ TEST 2 ]" << "\033[0m" << std::endl;
	try {
		Bureaucrat	bureaucrat("Bureaucrat", -19);

		std::cout << std::endl;
		std::cout << bureaucrat << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	/* TEST 3 */
	std::cout << "\033[1;34m" << "[ TEST 3 ]" << "\033[0m" << std::endl;
	try {
		Bureaucrat	bureaucrat("Bureaucrat", 175);

		std::cout << std::endl;
		std::cout << bureaucrat << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	/* TEST 4 */
	std::cout << "\033[1;34m" << "[ TEST 4 ]" << "\033[0m" << std::endl;
	try {
		Bureaucrat	bureaucrat("Bureaucrat", 1);

		std::cout << std::endl;
		std::cout << bureaucrat << std::endl;
		bureaucrat.promoteGrade();
		std::cout << bureaucrat << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	/* TEST 5 */
	std::cout << "\033[1;34m" << "[ TEST 5 ]" << "\033[0m" << std::endl;
	try {
		Bureaucrat	bureaucrat("Bureaucrat", 150);

		std::cout << std::endl;
		std::cout << bureaucrat << std::endl;
		bureaucrat.demoteGrade();
		std::cout << bureaucrat << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
