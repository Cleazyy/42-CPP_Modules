/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:03:37 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/04 22:28:02 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

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
