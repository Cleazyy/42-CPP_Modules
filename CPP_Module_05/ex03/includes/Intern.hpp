/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:07:14 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/09 07:34:31 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern& rhs);
		Intern& operator=(const Intern& rhs);
		~Intern(void);

		void	execute(const Bureaucrat &executor) const;
};

#endif
