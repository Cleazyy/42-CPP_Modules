/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:35:41 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/04 22:20:38 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

MateriaSource::MateriaSource(void)
{
	// std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& rhs)
{
	// std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = rhs;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{
	// std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->_materias[i];
			this->_materias[i] = rhs._materias[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	// std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->_materias[i])
			delete this->_materias[i];
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = m;
			return ;
		}
}

AMateria*   MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; i++ )
		if (this->_materias[i] && this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	return (NULL);
}
