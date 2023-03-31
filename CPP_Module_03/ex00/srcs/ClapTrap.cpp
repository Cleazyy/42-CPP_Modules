/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:14:30 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/31 21:52:59 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

ClapTrap::ClapTrap(void) : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

/* ************************************************************************** */
/*                          Private Member functions                          */
/* ************************************************************************** */

void	ClapTrap::displayStatus(std::string content)
{
	std::cout << "ClapTrap " << this->_name << " " << content << std::endl;
}

void	ClapTrap::displayHealth(void)
{
	std::cout << "ClapTrap " << this->_name << " now has " << this->_hitPoints << " hit points!" << std::endl;
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
	{
		this->displayStatus("is dead!");
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		this->displayStatus("is out of energy points!");
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		this->displayStatus("is dead!");
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage!" << std::endl;
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	this->displayHealth();
	if (this->_hitPoints <= 0)
		this->displayStatus("is dead!");
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		this->displayStatus("is dead!");
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		this->displayStatus("is out of energy points!");
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " repairs itself for " << amount << " hit points!" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints--;
	this->displayHealth();
}
