/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:23:18 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/05 18:17:49 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

Bureaucrat::Bureaucrat(void) : _name("Default Bureaucrat"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat setter default constructor called" << std::endl;
	try
	{
		if (this->_grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (this->_grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (Bureaucrat::GradeTooHighException ex)
	{
		this->_grade = 1;
		std::cout << this->_name << "'s " << ex.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException ex)
	{
		this->_grade = 150;
		std::cout << this->_name << "'s " << ex.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : _name(rhs._name)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = rhs;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	try
	{
		if (this->_grade - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade--;
	}
	catch (Bureaucrat::GradeTooHighException ex)
	{
		std::cout << "Error: " << this->_name << "'s " << ex.what() << std::endl;
	}
		
}

void	Bureaucrat::decrementGrade(void)
{
	try
	{
		if (this->_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade++;
	}
	catch (Bureaucrat::GradeTooLowException ex)
	{
		std::cout << "Error: " << this->_name << "'s " << ex.what() << std::endl;
	}
}

/* ************************************************************************** */
/*                            Exceptions functions                            */
/* ************************************************************************** */

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

/* ************************************************************************** */
/*                                   Other                                    */
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}
