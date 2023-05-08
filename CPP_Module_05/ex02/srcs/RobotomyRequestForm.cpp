/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:32:17 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/08 14:17:45 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
	// std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	// std::cout << "RobotomyRequestForm setter default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) : AForm(rhs), _target(rhs._target)
{
	// std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = rhs;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	// std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	(void) rhs;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	// std::cout << "Bureaucrat destructor called" << std::endl;
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (this->getSigned() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << "...vrrrrrrrrr..." << std::endl;
		std::srand(std::time(NULL));
		if (std::rand() % 2 == 0)
			std::cout << this->_target << " has been robotomized" << std::endl;
		else
			std::cout << this->_target << "'s robotomy has failed!" << std::endl;
	}
}
