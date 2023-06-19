/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:37:45 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/02 13:37:54 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

Dog::Dog(void) : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog &rhs)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = rhs;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_type = "Dog";
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

void Dog::makeSound(void) const
{
	std::cout << "Wouaf Wouaf!" << std::endl;
}