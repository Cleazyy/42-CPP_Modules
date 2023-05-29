/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:18:55 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/29 09:20:20 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */

Harl::Harl(void) {}

Harl::~Harl(void) {}

/* ************************************************************************** */
/*                          Private Member functions                          */
/* ************************************************************************** */

void Harl::_debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void Harl::_info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void Harl::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::_error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

void Harl::complain(std::string level)
{
	std::string tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*func[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	for (int i = 0; i < 4; i++) {
		if (level.compare(tab[i]) == 0) {
			(this->*func[i])();
			break ;
		}
	}
}
