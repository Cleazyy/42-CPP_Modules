/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:34:34 by fluchten          #+#    #+#             */
/*   Updated: 2023/06/19 10:25:08 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

Cure::Cure(void) : AMateria("cure")
{
	// std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &rhs) : AMateria("cure")
{
	// std::cout << "Cure copy constructor called" << std::endl;
    *this = rhs;
}

Cure &Cure::operator=(const Cure &rhs)
{
	// std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}

Cure::~Cure(void)
{
	// std::cout << "Cure destructor called" << std::endl;
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

AMateria *Cure::clone(void) const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
