/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:29:53 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/29 09:06:04 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}

	return (horde);
}