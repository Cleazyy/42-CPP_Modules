/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:23:26 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/09 10:26:49 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


int	main(void)
{
	/* TEST 1 */
	std::cout << "\033[1;34m" << "[ TEST 1 ]" << "\033[0m" << std::endl;
	try {
		Bureaucrat	bureaucrat("John", 1);
		Intern		someRandomIntern;
		AForm*		rrf;

		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		std::cout << *rrf << std::endl;
		bureaucrat.signForm(*rrf);
		bureaucrat.executeForm(*rrf);
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	/* TEST 2 */
	std::cout << "\033[1;34m" << "[ TEST 2 ]" << "\033[0m" << std::endl;
	try {
		Bureaucrat	bureaucrat("John", 1);
		Intern		someRandomIntern;
		AForm*		rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		bureaucrat.signForm(*rrf);
		bureaucrat.executeForm(*rrf);
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	/* TEST 3 */
	std::cout << "\033[1;34m" << "[ TEST 3 ]" << "\033[0m" << std::endl;
	try {
		Bureaucrat	bureaucrat("John", 1);
		Intern		someRandomIntern;
		AForm*		rrf;

		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout << *rrf << std::endl;
		bureaucrat.signForm(*rrf);
		bureaucrat.executeForm(*rrf);
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	/* TEST 4 */
	std::cout << "\033[1;34m" << "[ TEST 4 ]" << "\033[0m" << std::endl;
	try {
		Bureaucrat	bureaucrat("John", 1);
		Intern		someRandomIntern;
		AForm*		rrf;

		rrf = someRandomIntern.makeForm("random form", "Bender");
		std::cout << *rrf << std::endl;
		bureaucrat.signForm(*rrf);
		bureaucrat.executeForm(*rrf);
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
