/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:56:19 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/09 13:04:05 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

Form::Form(void) : _name("Default Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form setter default constructor called" << std::endl;
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& rhs) : _name(rhs._name), _signed(rhs._signed), _gradeToSign(rhs._gradeToSign), _gradeToExecute(rhs._gradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = rhs;
}

Form&	Form::operator=(const Form& rhs)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

Form::~Form(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

int	Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

/* ************************************************************************** */
/*                            Exceptions functions                            */
/* ************************************************************************** */

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

/* ************************************************************************** */
/*                             Operators Overloads                            */
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& o, const Form& rhs)
{
	o << "Form name: " << rhs.getName() << ", Signed: " << rhs.getSigned() << ", Sign grade: " << rhs.getGradeToSign() << ", Execute grade: " << rhs.getGradeToExecute();
	return (o);
}