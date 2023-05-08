/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:32:17 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/08 14:49:29 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("Default Target")
{
	// std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	// std::cout << "PresidentialPardonForm setter default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs) : AForm(rhs), _target(rhs._target)
{
	// std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = rhs;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	// std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	(void) rhs;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	// std::cout << "Bureaucrat destructor called" << std::endl;
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (this->getSigned() == false)
		throw AForm::NotSignedException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
