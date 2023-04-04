/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:09:14 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/04 20:27:06 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(const Cure& rhs);
		Cure& operator=(const Cure& rhs);
		~Cure(void);

		virtual AMateria*   clone() const;
		virtual void        use(ICharacter& target);
};

#endif
