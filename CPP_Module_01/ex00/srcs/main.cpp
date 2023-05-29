/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:04:18 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/29 09:04:01 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie carlos = Zombie("Carlos");
	Zombie *murillo = newZombie("Murillo");
	randomChump("Marwane");

	delete murillo;

	return (0);
}
