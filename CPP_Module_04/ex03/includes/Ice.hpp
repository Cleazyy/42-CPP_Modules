/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:19:35 by fluchten          #+#    #+#             */
/*   Updated: 2023/06/19 10:19:55 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{

    public:
        Ice(void);
        Ice(const Ice& rhs);
        Ice& operator=(const Ice& rhs);
        ~Ice(void);

        virtual AMateria *clone(void) const;
        virtual void use(ICharacter &target);
};

#endif
