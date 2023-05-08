/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:23:26 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/08 13:11:54 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	/* TEST 1 */
	std::cout << "\033[1;34m" << "[ TEST 1 ]" << "\033[0m" << std::endl;
	try {
		Bureaucrat				bureaucrat("Bureaucrat", 5);
		PresidentialPardonForm	form("President");

		std::cout << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
