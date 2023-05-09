/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:07:23 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/09 10:13:24 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

Intern::Intern(void)
{
	// std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& rhs)
{
	// std::cout << "Intern copy constructor called" << std::endl;
	*this = rhs;
}

Intern&	Intern::operator=(const Intern& rhs)
{
	// std::cout << "Intern copy assignment operator called" << std::endl;
	(void) rhs;
	return (*this);
}

Intern::~Intern(void)
{
	// std::cout << "Intern destructor called" << std::endl;
}

/* ************************************************************************** */
/*                          Private Member functions                          */
/* ************************************************************************** */

AForm	*Intern::_newShrubberyCreationForm(std::string target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::_newRobotomyRequestForm(std::string target) const
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::_newPresidentialPardonForm(std::string target) const
{
	return (new PresidentialPardonForm(target));
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

AForm	*Intern::makeForm(std::string name, std::string target) const
{
	std::string tab[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int	i = 0;

	while (i < 3 && name != tab[i])
		i++;
	switch (i)
	{
		case 0:
			return (this->_newShrubberyCreationForm(target));
		case 1:
			return (this->_newRobotomyRequestForm(target));
		case 2:
			return (this->_newPresidentialPardonForm(target));
		default:
			throw Intern::UnknownFormException();
	}
	return (NULL);
}

/* ************************************************************************** */
/*                            Exceptions functions                            */
/* ************************************************************************** */

const char	*Intern::UnknownFormException::what() const throw()
{
	return ("Form doesn't exist");
}
