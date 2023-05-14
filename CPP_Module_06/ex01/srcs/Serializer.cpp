/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:51:48 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/14 11:12:55 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

Serializer::Serializer(void)
{
	std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &rhs)
{
	std::cout << "Serializer copy constructor called" << std::endl;
	*this = rhs;
}

Serializer	&Serializer::operator=(const Serializer &rhs)
{
	std::cout << "Serializer copy assignment operator called" << std::endl;
	(void) rhs;
	return (*this);
}

Serializer::~Serializer(void)
{
	std::cout << "Serializer destructor called" << std::endl;
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
