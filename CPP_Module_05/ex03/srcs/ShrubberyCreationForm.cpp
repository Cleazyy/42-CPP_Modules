/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:32:17 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/08 14:49:25 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* ************************************************************************** */
/*                               Canonical form                               */
/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("Default Target")
{
	// std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	// std::cout << "ShrubberyCreationForm setter default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) : AForm(rhs), _target(rhs._target)
{
	// std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = rhs;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	// std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	(void) rhs;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	// std::cout << "Bureaucrat destructor called" << std::endl;
}

/* ************************************************************************** */
/*                          Public Member functions                           */
/* ************************************************************************** */

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (this->getSigned() == false)
		throw AForm::NotSignedException();
	std::ofstream outputFile(this->_target + "_shrubbery");
	if (!outputFile.is_open())
	{
		std::cout << "Failed to create '" << this->_target + "_shrubbery" << std::endl;
		return ;
	}
	std::string tree =
	"          &&& &&  & &&\n"
	"      && &\\/&&\\|& ()|/ @, &&\n"
	"      &\\/(/&/&||/& /_/)_&/_&\n"
	"   &() &\\/&|()|/&\\/ '%\" & ()\n"
	"  &_\\_\\&&_\\ |& |&&/&__%_/_& &&\n"
	"&&   && & &| &| /& & % ()& /&&\n"
	" ()&_---()&\\&\\|&&-&&--%---()~\n"
	"     &&     \\|||\n"
	"             |||\n"
	"             |||\n"
	"             |||\n"
	"       , -=-~  .-^- _\n";
	outputFile << tree;
	outputFile.close();
}
