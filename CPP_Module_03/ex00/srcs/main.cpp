/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:03:37 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/01 12:55:08 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	cortiz("Cortiz");
	ClapTrap	murillo("Murillo");
	ClapTrap	marwane("Marwane");

	std::cout << std::endl;
	std::cout << "\033[1;36m" << "[ ATTACK ]" << "\033[0m" << std::endl;
	for (int i = 1; i <= 12; i++)
	{
		std::cout << "[" << i << "] ";
		cortiz.attack("Murillo");
	}
	std::cout << std::endl;

	std::cout << "\033[1;31m" << "[ TAKE DAMAGE ]" << "\033[0m" << std::endl;
	murillo.takeDamage(7);
	murillo.takeDamage(5);
	murillo.takeDamage(1);
	murillo.takeDamage(2);
	marwane.takeDamage(4);
	std::cout << std::endl;

	std::cout << "\033[1;32m" << "[ BE REPAIRED ]" << "\033[0m" << std::endl;
	cortiz.beRepaired(3);
	murillo.beRepaired(8);
	marwane.beRepaired(2);
	marwane.beRepaired(5);
	std::cout << std::endl;

	return (0);
}