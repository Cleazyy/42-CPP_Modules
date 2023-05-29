/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:05:14 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/29 09:15:15 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */

Zombie::Zombie(void) : _name("Default Zombie")
{
	std::cout << "\033[1;32m" << this->_name << " was created." << "\033[0m" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "\033[1;31m" << this->_name << " has been destroyed." << "\033[0m" << std::endl;
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

void Zombie::announce(void)
{
	std::cout << "\033[1;33m" << this->_name << ": BraiiiiiiinnnzzzZ..." << "\033[0m" << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}
