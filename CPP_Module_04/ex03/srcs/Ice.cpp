/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:34:44 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/04 21:57:18 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

Ice::Ice(void) : AMateria("ice")
{
	// std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& rhs) : AMateria("cure")
{
	// std::cout << "Ice copy constructor called" << std::endl;
	*this = rhs;
}

Ice&	Ice::operator=(const Ice& rhs)
{
	// std::cout << "Ice copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

Ice::~Ice(void)
{
	// std::cout << "Ice destructor called" << std::endl;
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

AMateria*   Ice::clone(void) const
{
    return (new Ice(*this));
}

void    Ice::use(ICharacter& target)
{
    std::cout << "I shoots an ice bolt at " << target.getName() << std::endl;
}
