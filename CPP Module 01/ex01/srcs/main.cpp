/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:04:18 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/13 20:15:38 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *horde = zombieHorde(5, "Zombie N");

	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}