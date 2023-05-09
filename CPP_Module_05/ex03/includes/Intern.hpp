/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:07:14 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/09 10:13:42 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		AForm	*_newPresidentialPardonForm(std::string target) const;
		AForm	*_newRobotomyRequestForm(std::string target) const;
		AForm	*_newShrubberyCreationForm(std::string target) const;

	public:
		Intern(void);
		Intern(const Intern& rhs);
		Intern& operator=(const Intern& rhs);
		~Intern(void);

		AForm	*makeForm(std::string name, std::string target) const;

		class UnknownFormException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

#endif
