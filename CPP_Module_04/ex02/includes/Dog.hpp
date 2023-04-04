/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:35:15 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/04 22:27:53 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
{
	private:
		Brain	*_brain;

	public:
		Dog(void);
		Dog(const Dog& rhs);
		Dog& operator=(const Dog& rhs);
		~Dog(void);

		void	makeSound(void) const;
};

#endif
