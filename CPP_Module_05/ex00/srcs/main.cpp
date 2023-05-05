/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:23:26 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/05 12:57:01 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	bureaucrat("Bureaucrat", 42);

	std::cout << std::endl;
	std::cout << bureaucrat << std::endl;
	for (int i = 0; i < 24; i++)
		bureaucrat.incrementGrade();
	std::cout << bureaucrat << std::endl;
	bureaucrat.decrementGrade();
	std::cout << bureaucrat << std::endl;
	std::cout << std::endl;

	return (0);
}
