/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:23:26 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/04 19:19:13 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	unknow;
	Bureaucrat	carlos("Carlos", 19);
	Bureaucrat	murillo("Murillo", 42);
	Bureaucrat	marwane("Marwane", 21);
	Bureaucrat	invalid("Invalid", -10);

	std::cout << std::endl;
	std::cout << unknow << std::endl;
	std::cout << carlos << std::endl;
	std::cout << murillo << std::endl;
	std::cout << marwane << std::endl;
	std::cout << invalid << std::endl;
	std::cout << std::endl;

	return (0);
}
