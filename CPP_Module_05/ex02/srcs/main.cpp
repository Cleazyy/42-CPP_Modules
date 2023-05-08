/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:23:26 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/08 14:19:56 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	/* TEST 1 */
	std::cout << "\033[1;34m" << "[ TEST 1 ]" << "\033[0m" << std::endl;
	try {
		Bureaucrat				b1("John", 1);
		Bureaucrat				b2("Sarah", 1);
		PresidentialPardonForm	f1("Marc");
		RobotomyRequestForm		f2("Robot654");

		b1.signForm(f1);
		b1.executeForm(f1);
		std::cout << std::endl;
		b2.signForm(f2);
		b2.executeForm(f2);
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
