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

Dog::Dog(void) : AAnimal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& rhs)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = rhs._type;
	this->_brain = new Brain(*rhs._brain);
}

Dog&	Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

void	Dog::makeSound(void) const
{
	std::cout << "Wouaf Wouaf!" << std::endl;
}
