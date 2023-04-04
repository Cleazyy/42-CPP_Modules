/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:03:37 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/03 11:34:10 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal(void);
		Animal(const Animal& rhs);
		Animal& operator=(const Animal& rhs);
		virtual ~Animal(void);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif
