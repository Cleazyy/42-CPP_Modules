/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:04:18 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/29 09:05:25 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *horde = zombieHorde(NB_ZOMBIES, "Zombie N");

	for (int i = 0; i < NB_ZOMBIES; i++) {
		horde[i].announce();
	}

	delete [] horde;

	return (0);
}