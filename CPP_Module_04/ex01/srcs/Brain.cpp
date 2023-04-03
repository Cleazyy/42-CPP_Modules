/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:26:45 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/03 17:25:47 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& rhs)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = rhs;
}

Brain&	Brain::operator=(const Brain& rhs)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &rhs)
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}
