/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:03:37 by fluchten          #+#    #+#             */
/*   Updated: 2023/06/19 10:11:54 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
	protected:
		std::string	_type;

	public:
		AAnimal(void);
		AAnimal(const AAnimal &rhs);
		AAnimal &operator=(const AAnimal &rhs);
		virtual ~AAnimal(void);

		const std::string &getType(void) const;
		virtual void makeSound(void) const = 0;
};

#endif
