/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:19:35 by fluchten          #+#    #+#             */
/*   Updated: 2023/06/19 10:18:06 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria(void);
		AMateria(const std::string &type);
		AMateria(const AMateria &rhs);
		AMateria &operator=(const AMateria &rhs);
		virtual ~AMateria(void);

		const std::string &getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif
