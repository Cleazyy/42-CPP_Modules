/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:52:50 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/25 17:20:23 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
	return ;
}

HumanA::~HumanA(void)
{
	return ;
}

void	HumanA::attack(void)
{
	if (this->_weapon.getType() != "")
	    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	else
		std::cout << this->_name << " attacks with his fists" << std::endl;
}