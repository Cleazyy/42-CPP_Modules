/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:05:14 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/13 20:14:14 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : _name("Default Zombie")
{
	std::cout << "\033[1;32m" << _name << " was created." << "\033[0m" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "\033[1;31m" << _name << " has been destroyed." << "\033[0m" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << "\033[1;33m" << _name << ": BraiiiiiiinnnzzzZ..." << "\033[0m" << std::endl;
}

void	Zombie::setName(std::string name)
{
	_name = name;
}