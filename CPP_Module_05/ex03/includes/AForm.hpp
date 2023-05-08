/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:56:18 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/08 13:15:41 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		AForm(void);
		AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
		AForm(const AForm& rhs);
		AForm& operator=(const AForm& rhs);
		virtual ~AForm(void);

		std::string		getName(void) const;
		bool			getSigned(void) const;
		int				getGradeToSign(void) const;
		int				getGradeToExecute(void) const;

		void			beSigned(Bureaucrat &bureaucrat);
		virtual void	execute(const Bureaucrat &executor) const = 0;

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
		class NotSignedException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& o, const AForm& rhs);

#endif
