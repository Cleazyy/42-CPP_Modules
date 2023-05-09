/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:23:22 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/09 12:33:52 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BREAUCRAT_HPP
# define BREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& rhs);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat(void);

		std::string		getName(void) const;
		int				getGrade(void) const;

		void			promoteGrade(void);
		void			demoteGrade(void);
		void			signForm(Form &form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& rhs);

#endif
