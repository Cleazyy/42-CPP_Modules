/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:52:52 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/29 09:16:08 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */

HumanB::HumanB(std::string name) : _name(name) {}

HumanB::~HumanB(void) {}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack(void)
{
	if (this->_weapon->getType() != "") {
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	} else {
		std::cout << this->_name << " attacks with his fists" << std::endl;
	}
}