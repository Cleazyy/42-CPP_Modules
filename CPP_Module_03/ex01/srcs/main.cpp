/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:03:37 by fluchten          #+#    #+#             */
/*   Updated: 2023/06/01 19:30:17 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap cortiz("Cortiz");
	ScavTrap murillo("Murillo");
	ScavTrap marwane("Marwane");

	std::cout << std::endl;
	std::cout << "\033[1;36m" << "[ ATTACK ]" << "\033[0m" << std::endl;
	cortiz.attack("Murillo");
	cortiz.attack("Marwane");
	std::cout << std::endl;

	std::cout << "\033[1;31m" << "[ TAKE DAMAGE ]" << "\033[0m" << std::endl;
	murillo.takeDamage(85);
	murillo.takeDamage(15);
	murillo.takeDamage(1);
	murillo.takeDamage(2);
	murillo.takeDamage(3);
	marwane.takeDamage(25);
	std::cout << std::endl;

	std::cout << "\033[1;32m" << "[ BE REPAIRED ]" << "\033[0m" << std::endl;
	cortiz.beRepaired(3);
	murillo.beRepaired(8);
	marwane.beRepaired(2);
	marwane.beRepaired(5);
	std::cout << std::endl;

	std::cout << "\033[1;34m" << "[ GUARD GATE ]" << "\033[0m" << std::endl;
	cortiz.guardGate();
	murillo.guardGate();
	marwane.guardGate();
	std::cout << std::endl;

	return (0);
}