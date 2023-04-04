/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:19:35 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/04 12:39:05 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

# include <iostream>

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(const std::string& type);
		Ice(const Ice& rhs);
		Ice& operator=(const Ice& rhs);
		~Ice(void);

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif
