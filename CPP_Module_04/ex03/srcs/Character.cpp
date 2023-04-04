/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:19:29 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/04 22:25:55 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

Character::Character(void) : _name("Default")
{
	// std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i ++)
		this->_inventory[i] = NULL;
}

Character::Character(const std::string& name) : _name(name)
{
	// std::cout << "Character set name constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& rhs)
{
	// std::cout << "Character copy constructor called" << std::endl;
	*this = rhs;
}

Character&	Character::operator=(const Character& rhs)
{
	// std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++)
		{
			delete this->_inventory[i];
			this->_inventory[i] = rhs._inventory[i]->clone();
		}
	return (*this);
}

Character::~Character()
{
	// std::cout << "AMateria destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

const std::string&	Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	std::cout << "Error: " << this->_name << "'s inventory is full!" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && this->_inventory[idx])
	{
		delete this->_inventory[idx];
		this->_inventory[idx] = NULL;
	}
	else
		std::cout << "Error: " << this->_name << " does not have a materia equipped with this index!" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << "Error: " << this->_name << " does not have a materia equipped with this index!" << std::endl;
}
